import java.util.HashMap;
import java.util.Map;

public class SimpleLLM {
    private Map<String, Integer> wordCount;

    public SimpleLLM() {
        wordCount = new HashMap<>();
    }

    public void train(String text) {
        String[] words = text.split("\\s+");
        for (String word : words) {
            wordCount.put(word, wordCount.getOrDefault(word, 0) + 1);
        }
    }

    public int getWordCount(String word) {
        return wordCount.getOrDefault(word, 0);
    }

    public static void main(String[] args) {
        SimpleLLM model = new SimpleLLM();
        model.train("hello world hello");
        System.out.println("Count of 'hello': " + model.getWordCount("hello"));
        System.out.println("Count of 'world': " + model.getWordCount("world"));
    }
}
