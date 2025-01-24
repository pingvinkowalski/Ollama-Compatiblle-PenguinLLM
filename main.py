class SimpleLLM:
    def __init__(self):
        self.word_count = {}

    def train(self, text):
        words = text.split()
        for word in words:
            if word in self.word_count:
                self.word_count[word] += 1
            else:
                self.word_count[word] = 1

    def get_word_count(self, word):
        return self.word_count.get(word, 0)

if __name__ == "__main__":
    model = SimpleLLM()
    model.train("hello world hello")
    print("Count of 'hello':", model.get_word_count("hello"))
    print("Count of 'world':", model.get_word_count("world"))
