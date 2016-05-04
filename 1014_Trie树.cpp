#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 11
#define MAX_CHAR_NUM 26

typedef struct tagNODE_S
{
	int count;
	char letter;
	struct tagNODE_S *child[MAX_CHAR_NUM];
}NODE_S;

NODE_S root;

NODE_S *allocAndInitNode(char c)
{
	NODE_S *node = (NODE_S *)malloc(sizeof(NODE_S));
	memset(node, 0, sizeof(NODE_S));
	node->letter = c;
	return node;
}

void addDict(NODE_S *node, char *word)
{
	char c = word[0];

	if ('\0' == c)
	{
		node->count++;
		return;
	}

	if (NULL == node->child[c - 'a'])
	{
		node->child[c - 'a'] = allocAndInitNode(c);
	}

	node->count++;
	addDict(node->child[c - 'a'], word + 1);

	return;
}

int calcPrefix(NODE_S *node, char *word)
{
	if (NULL == node)
	{
		return 0;
	}

	if ('\0' == word[0])
	{
		return node->count;
	}
	
	return calcPrefix(node->child[word[0] - 'a'], word + 1);
}

int main()
{
	int n, m, ans;
	int i;
	char word[MAX_WORD_LEN];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s", word);
		addDict(&root, word);
	}

	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		scanf("%s", word);
		ans = calcPrefix(&root, word);
		printf("%d\n", ans);
	}

	return 0;
}