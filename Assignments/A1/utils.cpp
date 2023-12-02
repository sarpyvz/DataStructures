#include <algorithm>
#include <functional>
#include <random>
#include <unordered_map>
#include "TemplateLList.h"

/**
 * @brief Generates a random integer between lower and upper (inclusive)
 *
 * @param lower Lower bound of the range for the random integer
 * @param upper Upper bound of the range for the random integer
 * @return int Random integer between lower and upper
 */
int getRandomInt(int lower = 0, int upper = 100)
{
    static std::random_device rd; // Generates seed value for mt19937 (pseudo-random), static so that it is only initialized once
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(lower, upper); // Uniform distribution
    return dis(gen);
}

template <class T>
TemplateLList<T> sortListWithoutModifyingNodes(const TemplateLList<T> &list)
{
    // YOUR SOLUTION SHOULD BE WRITE IN HERE
    TemplateLLNode<T>* prev;
    TemplateLLNode<T>* curr;
    TemplateLLNode<T>* for_size;
    prev = list.head;
    curr = list.head->next;
    int count = 0;
    int temp;
    TemplateLLNode<T>* check;
    int size;
    for (for_size = list.head; for_size != NULL; for_size = curr->next){
            ++size;
        }
    while ( count != size -1){
        count = 0;
        if ( prev -> info > curr->info ){
            temp = curr->info;
            curr->info = prev->info;
            prev->info = temp;
        }
        for ( check = list.head; check != NULL; check = check->next){
            if ( check->info < (check->next)->info ){
                count++;
            } 
        
        }
        if ( count == size-1){
            return list;
        }

    }
    return list;
}
