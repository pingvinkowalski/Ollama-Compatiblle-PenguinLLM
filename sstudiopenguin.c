#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

typedef struct {
    WordCount wordCounts[MAX_WORDS];
    int size;
} SimpleLLM;

void train(SimpleLLM* model, const char* text) {
    char* token = strtok(text, " ");
    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < model->size; i++) {
            if (strcmp(model->wordCounts[i].word, token) == 0) {
                model->wordCounts[i].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(model->wordCounts[model->size].word, token);
            model->wordCounts[model->size].count = 1;
            model->size++;
        }
        token = strtok(NULL, " ");
    }
}

int getWordCount(SimpleLLM* model, const char* word) {
    for (int i = 0; i < model->size; i++) {
        if (strcmp(model->wordCounts[i].word, word) == 0) {
            return model->wordCounts[i].count;
        }
    }
    return 0;
}

int main() {
    SimpleLLM model = { .size = 0 };
    char text[] = "hello world hello";
    train(&model, text);
    printf("Count of 'hello': %d\n", getWordCount(&model, "hello"));
    printf("Count of 'world': %d\n", getWordCount(&model, "world"));
    return 0;
}
