#include "MorseTree.h"

namespace morse {
    MorseTree* MorseTree::itu() {
        MorseTree *tree = new MorseTree();

        tree->insert('E', ".", 1);
        tree->insert('T', "-", 1);
        tree->insert('I', "..", 2);
        tree->insert('A', ".-", 2);
        tree->insert('N', "-.", 2);
        tree->insert('M', "--", 2);
        tree->insert('S', "...", 3);
        tree->insert('U', "..-", 3);
        tree->insert('R', ".-.", 3);
        tree->insert('W', ".--", 3);
        tree->insert('D', "-..", 3);
        tree->insert('K', "-.-", 3);
        tree->insert('G', "--.", 3);
        tree->insert('O', "---", 3);
        tree->insert('H', "....", 4);
        tree->insert('V', "...-", 4);
        tree->insert('F', "..-.", 4);
        tree->insert('L', ".-..", 4);
        tree->insert('P', ".--.", 4);
        tree->insert('J', ".---", 4);
        tree->insert('B', "-...", 4);
        tree->insert('X', "-..-", 4);
        tree->insert('C', "-.-.", 4);
        tree->insert('Y', "-.--", 4);
        tree->insert('Z', "--..", 4);
        tree->insert('Q', "--.-", 4);

        tree->insert('1', ".----", 5);
        tree->insert('2', "..---", 5);
        tree->insert('3', "...--", 5);
        tree->insert('4', "....-", 5);
        tree->insert('5', ".....", 5);
        tree->insert('6', "-....", 5);
        tree->insert('7', "--...", 5);
        tree->insert('8', "---..", 5);
        tree->insert('9', "----.", 5);
        tree->insert('0', "-----", 5);

        // tree->insert('1', {DIT, DIT, DIT, DIT, DAH}, 5);
        // tree->insert('2', {DIT, DIT, DIT, DAH, DAH}, 5);
        // tree->insert('3', {DIT, DIT, DAH, DAH, DAH}, 5);
        // tree->insert('4', {DIT, DAH, DAH, DAH, DAH}, 5);
        // tree->insert('5', {DAH, DAH, DAH, DAH, DAH}, 5);
        // tree->insert('6', {DIT, DIT, DIT, DIT, DIT}, 5);
        // tree->insert('7', {DAH, DIT, DIT, DIT, DIT}, 5);
        // tree->insert('8', {DAH, DAH, DIT, DIT, DIT}, 5);
        // tree->insert('9', {DAH, DAH, DAH, DIT, DIT}, 5);
        // tree->insert('0', {DAH, DAH, DAH, DAH, DIT}, 5);

        // tree->insert('.', {DIT, DAH, DIT, DAH, DIT, DAH}, 6);
        // tree->insert(',', {DAH, DAH, DIT, DIT, DAH, DAH}, 6);
        // tree->insert(':', {DAH, DAH, DAH, DIT, DIT, DIT}, 6);
        // tree->insert('?', {DIT, DIT, DAH, DAH, DIT, DIT}, 6);
        // tree->insert('\'', {DIT, DAH, DAH, DAH, DAH, DIT}, 6);
        // tree->insert('-', {DAH, DIT, DIT, DIT, DIT, DAH}, 6);
        // tree->insert('/', {DAH, DIT, DIT, DAH, DIT}, 5);
        // tree->insert('(', {DAH, DIT, DAH, DAH, DIT}, 5);
        // tree->insert(')', {DAH, DIT, DAH, DAH, DIT, DAH}, 6);
        // tree->insert('"', {DIT, DAH, DIT, DIT, DAH, DIT}, 6);
        // tree->insert('=', {DAH, DIT, DIT, DIT, DAH}, 5);
        // tree->insert('+', {DIT, DAH, DIT, DAH, DIT}, 5);
        // tree->insert('@', {DIT, DAH, DAH, DIT, DAH, DIT}, 6);

        // FIXME: How to add special characters specified in ITU-R M.1677-1?
        // https://www.itu.int/dms_pubrec/itu-r/rec/m/R-REC-M.1677-1-200910-I!!PDF-E.pdf

        return tree;
    }

    void MorseTree::insert(char value, const char *signals, int length) {
        MorseNode* current = root;
        for (int i = 0; i < length; i++) {
            if (signals[i] == '.') {
                if (current->left == nullptr) {
                    current->left = new MorseNode();
                    current->left->value = '\0';
                    current->left->left = nullptr;
                    current->left->right = nullptr;
                }
                current = current->left;
            } else {
                if (current->right == nullptr) {
                    current->right = new MorseNode();
                    current->right->value = '\0';
                    current->right->left = nullptr;
                    current->right->right = nullptr;
                }
                current = current->right;
            }
        }
        current->value = value;
    }
}
