#include <iostream>
#include "board.h"
#define SIZE 5
using namespace std;

class BoardArray : public Board {
    Entry* array;
    int index;

    public:
        BoardArray() {
            array = new Entry[SIZE];
            index = 0;
        }

        void add(Entry* entry) {
            // TODO: IMPLEMENT THIS FUNCTION
            // ALGORITHM IS PROVIDED IN INSTRUCTIONS.TXT
            if (index == SIZE && entry->score <= array[SIZE - 1].score) {
                cout << entry->name << "'s score is too low to be added!" << endl;
                return;
    }
            int pos = index;
            while (pos > 0 && entry->score > array[pos - 1].score) {
                if (pos < SIZE) array[pos] = array[pos - 1];
                    pos--;
    }
            if (pos < SIZE) array[pos] = *entry;
    
            if (index < SIZE) index++;
}

        void print() {
            for (int i = 0; i < index; i++) {
                cout << i + 1 << ". ";
                array[i].print();
            }
        }
};