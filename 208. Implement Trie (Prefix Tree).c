#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct TrieNode
{
    struct TrieNode* children[26];
    bool tag;
} TrieNode;

TrieNode* nodeCreate(void)
{
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    memset(node->children, 0, sizeof(node->children));
    node->tag = false;
    return node;
}

void nodeFree(TrieNode* node)
{
    for (int i = 0; i < 26; i++)
    {
        if (node->children[i])
        {
            nodeFree(node->children[i]);
        }
    }
    free(node);
}

typedef struct
{
    TrieNode* root;
} Trie;

Trie* trieCreate(void)
{
    Trie* obj = (Trie*)malloc(sizeof(Trie));
    obj->root = nodeCreate();
    return obj;
}

void trieInsert(Trie* obj, char* word)
{
    TrieNode* node = obj->root;
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (node->children[word[i] - 'a'] == NULL)
        {
            node->children[word[i] - 'a'] = nodeCreate();
        }
        node = node->children[word[i] - 'a'];
    }
    node->tag = true;
}

bool trieSearch(Trie* obj, char* word)
{
    TrieNode* node = obj->root;
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (node->children[word[i] - 'a'] == NULL)
        {
            return false;
        }
        node = node->children[word[i] - 'a'];
    }
    return node->tag;
}

bool trieStartsWith(Trie* obj, char* prefix)
{
    TrieNode* node = obj->root;
    for (int i = 0; prefix[i] != '\0'; i++)
    {
        if (node->children[prefix[i] - 'a'] == NULL)
        {
            return false;
        }
        node = node->children[prefix[i] - 'a'];
    }
    return true;
}

void trieFree(Trie* obj)
{
    nodeFree(obj->root);
    free(obj);
}
