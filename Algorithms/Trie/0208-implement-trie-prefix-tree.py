class Trie:
    class TrieNode:
        def __init__(self):
            self.cnt = 0
            self.next = [None] * 26


    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.tree = [Trie.TrieNode()]


    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        node = self.tree[0]
        for ch in map(lambda ch: ord(ch) - ord("a"), word):
            if node.next[ch] is None:
                node.next[ch] = Trie.TrieNode()
            node = node.next[ch]
        node.cnt += 1


    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        node = self.getNode(word)
        return node is not None and node.cnt > 0


    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        node = self.getNode(prefix)
        return node is not None


    def getNode(self, word: str) -> TrieNode:
        node = self.tree[0]
        for ch in map(lambda ch: ord(ch) - ord("a"), word):
            node = node.next[ch]
            if not node:
                break
        return node


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
