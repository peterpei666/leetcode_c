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

typedef struct {
    TrieNode* root;
} WordDictionary;

WordDictionary* wordDictionaryCreate(void)
{
    WordDictionary* obj = (WordDictionary*)malloc(sizeof(WordDictionary));
    obj->root = nodeCreate();
    return obj;
}

void wordDictionaryAddWord(WordDictionary* obj, char* word)
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

bool search(TrieNode* node, char* word, int idx)
{
    if (word[idx] == '\0')
    {
        return node->tag;
    }
    if (word[idx] == '.')
    {
        bool ans = false;
        for (int i = 0; i < 26 && !ans; i++)
        {
            if (node->children[i])
            {
                ans = search(node->children[i], word, idx + 1);
            }
        }
        return ans;
    }
    if (node->children[word[idx] - 'a'])
    {
        return search(node->children[word[idx] - 'a'], word, idx + 1);
    }
    return false;
}

bool wordDictionarySearch(WordDictionary* obj, char* word)
{
    return search(obj->root, word, 0);
}

void wordDictionaryFree(WordDictionary* obj)
{
    nodeFree(obj->root);
    free(obj);
}
