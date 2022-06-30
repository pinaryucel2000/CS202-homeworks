#include "AVL.h"

AVL::AVL()
{
    root = NULL;
}

AVL::~AVL()
{
    deleteAVL(root);
}

void AVL::addWord(string str)
{
    if(str == "")
    {
        return;
    }

    // If the specified word is a duplicate, return.
    if(!insert(root, str))
    {
        return;
    }

    setHeights(root, str);
    rotate(root, root, str);
    setHeights(root, str);
}

void AVL::rotate(TreeNode*& node, TreeNode*& unbalancedNode, string str)
{
    // Find the first unbalanced node from the added node to the root
    if(node != NULL)
    {
        if(!isBalanced(node))
        {
            if(node->item > str)
            {
                rotate(node->left, node, str);
            }
            else if(node->item < str)
            {
                rotate(node->right, node, str);
            }
        }
        else
        {
            if(node->item > str)
            {
                rotate(node->left, unbalancedNode, str);
            }
            else if(node->item < str)
            {
                rotate(node->right, unbalancedNode, str);
            }
        }
    }

    int balanceFactor = getBalanceFactor(unbalancedNode);
    TreeNode* topNode = NULL;

    // New item is added to the left child of the unbalanced node.
    if(balanceFactor > 1 && str < unbalancedNode->left->item)
    {
        rotateRight(unbalancedNode, topNode);
        unbalancedNode = topNode;

        return;
    }

    // New item is added to the right child of the unbalanced node.
    if(balanceFactor < -1 && str > unbalancedNode->right->item)
    {
        rotateLeft(unbalancedNode, topNode);
        unbalancedNode = topNode;

        return;
    }

    // New item is added to the right child of the left child of the unbalanced node.
    if(balanceFactor > 1 && str > unbalancedNode->left->item)
    {
        rotateLeft(unbalancedNode->left, topNode);
        unbalancedNode->left = topNode;
        rotateRight(unbalancedNode, topNode);
        unbalancedNode = topNode;

        return;
    }

    // New node is added to the left child of the right child of the unbalanced node.
    if(balanceFactor < -1 && str < unbalancedNode->right->item)
    {
        rotateRight(unbalancedNode->right, topNode);
        unbalancedNode->right = topNode;
        rotateLeft(unbalancedNode, topNode);
        unbalancedNode = topNode;

        return;
    }
}

int AVL::getBalanceFactor(TreeNode* node)
{
    if(node == NULL)
    {
        return 0;
    }
    else
    {
        return getHeight(node->left) - getHeight(node->right);
    }
}

int AVL::getHeight(TreeNode* node)
{
    if(node == NULL)
    {
        return 0;
    }
    else
    {
        return node->height;
    }
}

int AVL::calculateHeight(TreeNode* node)
{
    if(node == NULL)
    {
        return 0;
    }
    else
    {
        return max(calculateHeight(node->right), calculateHeight(node->left)) + 1;
    }
}

bool AVL::isBalanced(TreeNode* node)
{
    int balanceFactor = getBalanceFactor(node);
    return balanceFactor <= 1 && balanceFactor >= -1;
}

void AVL::rotateRight(TreeNode* node, TreeNode*& topNode)
{
    TreeNode* nodeLeft = node->left;
    node->left = nodeLeft->right;
    nodeLeft->right = node;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    nodeLeft->height = max(getHeight(nodeLeft->left), getHeight(nodeLeft->right)) + 1;

    topNode = nodeLeft;
}

void AVL::rotateLeft(TreeNode* node, TreeNode*& topNode)
{
    TreeNode* nodeRight = node->right;
    node->right = nodeRight->left;
    nodeRight->left = node;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    nodeRight->height = max(getHeight(nodeRight->left), getHeight(nodeRight->right)) + 1;

    topNode = nodeRight;
}

bool AVL::insert(TreeNode*& node, string str)
{
    if(node == NULL)
    {
        node = new TreeNode(str);
        return true;
    }
    else if(node->item > str)
    {
        return insert(node->left, str);
    }
    else if(node->item < str)
    {
        return insert(node->right, str);
    }
    else
    {
        node->count++;
        return false;
    }
}

void AVL::setHeights(TreeNode* node, string str)
{
    if(node == NULL)
    {
        return;
    }
    else
    {
        node->height = calculateHeight(node);

        if(node->item > str)
        {
            setHeights(node->left, str);
        }
        else if(node->item < str)
        {
            setHeights(node->right, str);
        }
        else
        {
            return;
        }
    }
}

TreeNode* AVL::retrieve(const string str)
{
    return retrieveHelper(root, str);
}

void AVL::generateTree(string fileName)
{
    string input = ""; // txt file content
    string word_ = ""; // a word in the txt file

    ifstream ifs;
    int fileNameSize = fileName.size();

    char* fileNamePtr = new char[fileNameSize];

    for(int i = 0; i < fileNameSize; i++)
    {
        fileNamePtr[i] = fileName[i];
    }

    ifs.open(fileNamePtr);

    while(ifs >> word_)
    {
        input = input + word_ + " ";
    }

    ifs.close();

    toLower(input);
    int size = 0;
    int start = 0;
    string word = "";
    int wordSize = 0;

    size = input.size();
    start = 0;

    for(int i = 0; i <= size; i++)
    {
        if(input[i] == ' ' || isNotValid(input[i]) || i == size)
        {
            word = input.substr(start, i - start);
            wordSize = word.size();
            addWord(word);
            start = start + wordSize + 1;
        }
    }

    delete [] fileNamePtr;
    fileNamePtr = NULL;
}

void AVL::printHeight()
{
    cout << "Tree Height: " << calculateHeight(root) << endl;
}

void AVL::printTotalWordCount()
{
    cout << "Total Word Count: " << getTotalWordCount(root) << endl;
}

void AVL::printWordFrequencies()
{
    printWordFrequenciesHelper(root);
    cout << endl;
}

void AVL::printMostFrequent()
{
    if(root == NULL)
    {
        cout << "Most Frequent: -" << endl;
        return;
    }

    TreeNode* mostFrequent = root;
    findMostFrequent(root, mostFrequent);

    if(mostFrequent != NULL)
    {
        cout << "Most Frequent: " << mostFrequent->item << " " << mostFrequent->count << endl;
    }
}

void AVL::printLeastFrequent()
{
    if(root == NULL)
    {
        cout << "Least Frequent: -" << endl;
        return;
    }

    TreeNode* leastFrequent = root;
    findLeastFrequent(root, leastFrequent);

    if(leastFrequent != NULL)
    {
        cout << "Least Frequent: " << leastFrequent->item << " " << leastFrequent->count << endl;
    }
}

void AVL::printStandartDeviation()
{
    if(root == NULL)
    {
        cout << "Standart Deviation: -" << endl;
        return;
    }

    int index = 0;
    int wordCount = getTotalWordCount(root);
    double sum = 0; // Sum of the frequencies.
    double mean = 0; // Mean of the frequencies.
    double sumOfDistanceSquares = 0;
    double tmp = 0;
    double standartDeviation = 0;

    int* frequencies = new int[wordCount];
    getFrequencies(root, frequencies, sum, index);
    mean = sum / wordCount;

    for(int i = 0; i < wordCount; i++)
    {
        tmp = frequencies[i] - mean;
        tmp = tmp * tmp;
        sumOfDistanceSquares = sumOfDistanceSquares + tmp;
    }

    standartDeviation = sqrt(sumOfDistanceSquares / wordCount);

    cout << "Standart Deviation: " << standartDeviation << endl;
}

void AVL::printWordFrequenciesToFile(string fileName)
{
    ofstream ofs;
    ofs.open(fileName.c_str());
    printWordFrequenciesToFileHelper(ofs, root);
    ofs.close();
}

void AVL::printStatisticsToFile(string fileName)
{
    ofstream ofs;
    ofs.open(fileName.c_str());

    ofs << "Total Word Count: " << getTotalWordCount(root) << endl;
    ofs << "Tree Height: " << getHeight(root) << endl;


    TreeNode* frequent = root;
    findMostFrequent(root, frequent);

    if(frequent == NULL)
    {
        ofs << "Most Frequent: -" << endl;
    }
    else
    {
        ofs << "Most Frequent: " << frequent->item << " " << frequent->count << endl;
    }

    frequent = root;
    findLeastFrequent(root, frequent);

    if(frequent == NULL)
    {
        ofs << "Least Frequent: -" << endl;
    }
    else
    {
        ofs << "Least Frequent: " << frequent->item << " " << frequent->count << endl;
    }

    if(root != NULL)
    {
        int index = 0;
        int wordCount = getTotalWordCount(root);
        double sum = 0; // Sum of the frequencies.
        double mean = 0; // Mean of the frequencies.
        double sumOfDistanceSquares = 0;
        double tmp = 0;
        double standartDeviation = 0;

        int* frequencies = new int[wordCount];
        getFrequencies(root, frequencies, sum, index);
        mean = sum / wordCount;

        for(int i = 0; i < wordCount; i++)
        {
            tmp = frequencies[i] - mean;
            tmp = tmp * tmp;
            sumOfDistanceSquares = sumOfDistanceSquares + tmp;
        }

        standartDeviation = sqrt(sumOfDistanceSquares / wordCount);
        ofs << "Standart Deviation: " << standartDeviation << endl;
    }
    else
    {
        ofs << "Standart Deviation: -" << endl;
    }

    ofs.close();
}

void AVL::deleteAVL(TreeNode* node)
{
    if(node != NULL)
    {
        deleteAVL(node->left);
        deleteAVL(node->right);
        delete node;
    }
}

TreeNode* AVL::retrieveHelper(TreeNode* node, const string str)
{
    if(node == NULL)
    {
        return NULL;
    }
    else if(node->item > str)
    {
        return retrieveHelper(node->left, str);
    }
    else if(node->item < str)
    {
        return retrieveHelper(node->right, str);
    }
    else
    {
        return node;
    }
}

void AVL::toLower(string& str)
{
    int size = str.size();

    for(int i = 0; i < size; i++)
    {
        if(str[i] == 'A')
        {
            str[i] = 'a';
        }
        else if(str[i] == 'B')
        {
            str[i] = 'b';
        }
        else if(str[i] == 'C')
        {
            str[i] = 'c';
        }
        else if(str[i] == 'D')
        {
            str[i] = 'd';
        }
        else if(str[i] == 'E')
        {
            str[i] = 'e';
        }
        else if(str[i] == 'F')
        {
            str[i] = 'f';
        }
        else if(str[i] == 'G')
        {
            str[i] = 'g';
        }
        else if(str[i] == 'H')
        {
            str[i] = 'h';
        }
        else if(str[i] == 'I')
        {
            str[i] = 'i';
        }
        else if(str[i] == 'J')
        {
            str[i] = 'j';
        }
        else if(str[i] == 'K')
        {
            str[i] = 'k';
        }
        else if(str[i] == 'L')
        {
            str[i] = 'l';
        }
        else if(str[i] == 'M')
        {
            str[i] = 'm';
        }
        else if(str[i] == 'N')
        {
            str[i] = 'n';
        }
        else if(str[i] == 'O')
        {
            str[i] = 'o';
        }
        else if(str[i] == 'P')
        {
            str[i] = 'p';
        }
        else if(str[i] == 'Q')
        {
            str[i] = 'q';
        }
        else if(str[i] == 'R')
        {
            str[i] = 'r';
        }
        else if(str[i] == 'S')
        {
            str[i] = 's';
        }
        else if(str[i] == 'T')
        {
            str[i] = 't';
        }
        else if(str[i] == 'U')
        {
            str[i] = 'u';
        }
        else if(str[i] == 'V')
        {
            str[i] = 'v';
        }
        else if(str[i] == 'W')
        {
            str[i] = 'w';
        }
        else if(str[i] == 'X')
        {
            str[i] = 'x';
        }
        else if(str[i] == 'Y')
        {
            str[i] = 'y';
        }
        else if(str[i] == 'Z')
        {
            str[i] = 'z';
        }
    }
}

bool AVL::isNotValid(const char str)
{
    if(str == 'a' || str == 'b' || str == 'c' || str == 'd' || str == 'e' || str == 'f' || str == 'g' || str == 'h' || str == 'i' || str == 'j' || str == 'k' ||
       str == 'l' || str == 'm' || str == 'n' || str == 'o' || str == 'p' || str == 'q' || str == 'r' || str == 's' || str == 't' || str == 'u' || str == 'v' ||
       str == 'w' || str == 'x' || str == 'y' || str == 'z' || str == '1' || str == '2' || str == '3' || str == '4' || str == '5' || str == '6' || str == '7' ||
       str == '8' || str == '9' || str == '0')
    {
        return false;
    }
    else
    {
        return true;
    }
}

int AVL::getTotalWordCount(TreeNode* node)
{
    if(node == NULL)
    {
        return 0;
    }
    else
    {
        return getTotalWordCount(node->left) + getTotalWordCount(node->right) + 1;
    }
}

void AVL::printWordFrequenciesHelper(TreeNode* node)
{
    if(node != NULL)
    {
        printWordFrequenciesHelper(node->left);
        cout << node->item << ": " << node->count << endl;
        printWordFrequenciesHelper(node->right);
    }
}

void AVL::findMostFrequent(TreeNode* node, TreeNode*& mostFrequent)
{
    if(node != NULL)
    {
        if(node->count > mostFrequent->count)
        {
            mostFrequent = node;
        }

        findMostFrequent(node->left, mostFrequent);
        findMostFrequent(node->right, mostFrequent);
    }
}

void AVL::findLeastFrequent(TreeNode* node, TreeNode*& leastFrequent)
{
    if(node != NULL)
    {
        if(node->count < leastFrequent->count)
        {
            leastFrequent = node;
        }

        findLeastFrequent(node->left, leastFrequent);
        findLeastFrequent(node->right, leastFrequent);
    }
}

void AVL::getFrequencies(TreeNode* node, int* arr, double& sum, int& index)
{
    if(node != NULL)
    {
        arr[index] = node->count;
        sum = sum + node->count;
        index++;
        getFrequencies(node->left, arr, sum, index);
        getFrequencies(node->right, arr, sum, index);
    }
}

void AVL::printWordFrequenciesToFileHelper(ofstream& ofs, TreeNode* node)
{
    if(node != NULL)
    {
        printWordFrequenciesToFileHelper(ofs, node->left);
        ofs << node->item << ": " << node->count << endl;
        printWordFrequenciesToFileHelper(ofs, node->right);
    }
}
