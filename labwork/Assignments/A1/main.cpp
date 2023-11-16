#include <iostream>
#include "TemplateLList.h"
#include "utils.cpp"

// Colors & Emoji for terminal output
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define MESSAGE "\033[5;31;43m"
#define DONE "\U0001F60E"
#define NOTDONE "\U0001F622"

// Print a separator line
void printSeparator()
{
    std::cout << CYAN << "-----------------------" << RESET << std::endl;
}

// Print a header line
void printHeader(const std::string &title)
{
    std::cout << YELLOW << title << ":" << RESET << std::endl;
}

// Print a list with a label
void printList(const std::string &label, const TemplateLList<int> &list)
{
    std::cout << MAGENTA << label << ":\t" << RESET;
    list.printAll();
}

// Print the result of a merge operation
void printMergeResult(bool success)
{
    std::cout << (success ? GREEN : RED) << (success ? "Merge success." : "Merge failed.") << RESET << std::endl;
}

int main()
{
    TemplateLList<int> list1;
    TemplateLList<int> list2;
    TemplateLList<int> list3;
    TemplateLList<int> list4;

    // Generate random lists
    for (int i = 0; i < 5; i++)
    {
        list1.addToTail(getRandomInt());
        list2.addToTail(getRandomInt());
        list3.addToTail(getRandomInt());
        list4.addToTail(getRandomInt());
    }

    // Print original lists
    printSeparator();
    printHeader("Original List 1");
    printList("List 1", list1);
    printHeader("Original List 2");
    printList("List 2", list2);
    printHeader("Original List 3");
    printList("List 3", list3);
    printHeader("Original List 4");
    printList("List 4", list4);

    // Sort List Without Modifying Nodes
    // printSeparator();
    // printHeader("Sorted List Without Modifying Nodes");
    // TemplateLList<int> sortedList = sortListWithoutModifyingNodes(list1);
    // printList("Sorted List 1", sortedList);

    // Rotate List
    printSeparator();
    printHeader("Rotated List");
    list2.rotate(2);
    printList("Rotated List 2, k=2", list2);

    printSeparator();
    printHeader("Rotated List");
    list3.rotate(-1);
    printList("Rotated List 3, k=-1", list3);

    printSeparator();
    printHeader("Rotated List");
    list4.rotate(9);
    printList("Rotated List 4 k=9", list4);

    return 0;
}
