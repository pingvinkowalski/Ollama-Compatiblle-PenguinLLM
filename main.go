package main

import (
    "fmt"
    "strings"
)

type SimpleLLM struct {
    wordCount map[string]int
}

func (model *SimpleLLM) train(text string) {
    words := strings.Fields(text)
    for _, word := range words {
        model.wordCount[word]++
    }
}

func (model *SimpleLLM) getWordCount(word string) int {
    return model.wordCount[word]
}

func main() {
    model := SimpleLLM{wordCount: make(map[string]int)}
    model.train("hello world hello")
    fmt.Println("Count of 'hello':", model.getWordCount("hello"))
    fmt.Println("Count of 'world':", model.getWordCount("world"))
}
