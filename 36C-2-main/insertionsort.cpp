// Insertion Sort
// 
// Author: Rob Gysel
// ECS60, UC Davis
// Adapted from: Lysecky & Vahid "Data Structures Essentials", zyBooks

#include "insertionsort.h"

void InsertionSort(std::vector<int>* numbers, int& mem_access_count, int& comparison_count) {
   int i = 0;
   int j = 0;
   int temp = 0;  // Temporary variable for swap

   for (i = 1; i < numbers->size(); ++i) {
      j = i;
      // Insert numbers[i] into sorted part
      // stopping once numbers[i] in correct position
      while (j > 0 && (*numbers)[j] < (*numbers)[j - 1]) {
         // Swap numbers[j] and numbers[j - 1]
         comparison_count++;
         temp = (*numbers)[j];
         (*numbers)[j] = (*numbers)[j - 1];
         (*numbers)[j - 1] = temp;
         --j;
         mem_access_count+=6;
      }
      if(j > 0){comparison_count++;mem_access_count+=2;}
   }
   return;
}