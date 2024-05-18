#pragma once

namespace morse {

// MorseNode is a node in the Morse tree.
//   - It has a value. If the value is not empty, the node represents a valid character.
//   - It has a left (for DIT) and right (for DAH) child.
struct MorseNode {
    char value;
    MorseNode* left;
    MorseNode* right;
};

// MorseTree is a binary tree that represents the Morse code.
class MorseTree {
public:
    static MorseTree* itu();
    
    class FSM;

    MorseTree() {
        root = new MorseNode();
        root->value = '\0';
        root->left = nullptr;
        root->right = nullptr;
    }

    virtual ~MorseTree() {};

    // Insert a Morse code signal into the tree.
    //   - value: the character value of the signal.
    //   - signals: the Morse code signals.
    //   - length: the length of the signals.
    void insert(char value, const char *signals, int length);

private:
    MorseNode* root;
};

class MorseTree::FSM {
public:
    FSM(MorseTree* tree) : tree(tree), current(tree->root) {}

    // Reset the FSM to the root node.
    void reset() {
        current = tree->root;
    }

    // Process a Morse code signal.
    //   - signal: the Morse code signal.
    // Return false if the signal leads to an invalid state, otherwise true.
    bool process(char signal) {
        if (signal == '.') {
            if (current->left == nullptr) {
                return false;
            }
            current = current->left;
        } else {
            if (current->right == nullptr) {
                return false;
            }
            current = current->right;
        }
        return true;
    }

    // Process a sequence of Morse code signals.
    bool process(const char *signals, int length) {
        for (int i = 0; i < length; i++) {
            if (!process(signals[i])) {
                return false;
            }
        }
        return true;
    }

    // Get the value of the current node.
    char getValue() {
        return current->value;
    }

private:
    MorseTree* tree;
    MorseNode* current;
};

}
