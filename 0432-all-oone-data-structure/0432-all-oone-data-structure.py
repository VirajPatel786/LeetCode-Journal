class FrequencyNode:
    def __init__(self, frequency):
        """
        Initializes a node that represents a specific frequency of keys.
        
        Parameters:
        frequency (int): The frequency associated with this node.

        Attributes:
        keys (set): Set of keys that share the same frequency.
        prev (FrequencyNode): Reference to the previous node in the doubly linked list.
        next (FrequencyNode): Reference to the next node in the doubly linked list.
        """
        self.frequency = frequency
        self.keys = set()  # A set to store keys with this frequency
        self.prev = None
        self.next = None


class AllOne:
    def __init__(self):
        """
        Initializes the AllOne data structure.

        Attributes:
        head (FrequencyNode): Dummy head node representing the lowest frequency.
        tail (FrequencyNode): Dummy tail node representing the highest frequency.
        key_to_node (dict): A dictionary mapping keys to their corresponding frequency node.
        """
        self.head = FrequencyNode(0)  # Dummy head for minimum frequency
        self.tail = FrequencyNode(0)  # Dummy tail for maximum frequency
        self.head.next = self.tail
        self.tail.prev = self.head
        self.key_to_node = {}  # Maps keys to the frequency node where they are stored

    def _add_node_after(self, prev_node, frequency):
        """
        Adds a new FrequencyNode with a given frequency after the prev_node in the linked list.

        Parameters:
        prev_node (FrequencyNode): The node after which the new node should be added.
        frequency (int): The frequency for the new node.

        Returns:
        FrequencyNode: The newly created frequency node.
        """
        new_node = FrequencyNode(frequency)
        new_node.prev = prev_node
        new_node.next = prev_node.next
        prev_node.next.prev = new_node
        prev_node.next = new_node
        return new_node

    def _remove_node_if_empty(self, node):
        """
        Removes a node from the linked list if it has no keys associated with it.

        Parameters:
        node (FrequencyNode): The node to remove if it is empty.
        """
        if not node.keys:
            node.prev.next = node.next
            node.next.prev = node.prev

    def inc(self, key: str) -> None:
        """
        Increments the count of the given key. If the key does not exist, it is added with a count of 1.

        Parameters:
        key (str): The key whose count is incremented.
        """
        if key in self.key_to_node:
            current_node = self.key_to_node[key]
            current_node.keys.remove(key)

            new_frequency = current_node.frequency + 1
            next_node = current_node.next

            # If the next node is not the tail and doesn't match the new frequency, create a new node
            if next_node == self.tail or next_node.frequency != new_frequency:
                next_node = self._add_node_after(current_node, new_frequency)

            next_node.keys.add(key)
            self.key_to_node[key] = next_node

            # Remove the current node if it has no keys left
            self._remove_node_if_empty(current_node)
        else:
            # If the key doesn't exist, initialize it with frequency 1
            first_node = self.head.next
            if first_node == self.tail or first_node.frequency != 1:
                first_node = self._add_node_after(self.head, 1)
            first_node.keys.add(key)
            self.key_to_node[key] = first_node

    def dec(self, key: str) -> None:
        """
        Decrements the count of the given key. If the count reaches 0, the key is removed from the data structure.

        Parameters:
        key (str): The key whose count is decremented.
        """
        if key not in self.key_to_node:
            return

        current_node = self.key_to_node[key]
        current_node.keys.remove(key)

        if current_node.frequency == 1:
            # If the frequency is 1, remove the key entirely
            del self.key_to_node[key]
        else:
            new_frequency = current_node.frequency - 1
            prev_node = current_node.prev

            # If the previous node doesn't match the new frequency, create a new node
            if prev_node == self.head or prev_node.frequency != new_frequency:
                prev_node = self._add_node_after(current_node.prev, new_frequency)

            prev_node.keys.add(key)
            self.key_to_node[key] = prev_node

        # Remove the current node if it has no keys left
        self._remove_node_if_empty(current_node)

    def getMaxKey(self) -> str:
        """
        Returns one of the keys with the highest count. If no key exists, returns an empty string.

        Returns:
        str: A key with the highest count, or an empty string if no key exists.
        """
        if self.tail.prev == self.head:
            return ""  # No keys present
        return next(iter(self.tail.prev.keys))  # Return any key from the highest frequency node

    def getMinKey(self) -> str:
        """
        Returns one of the keys with the lowest count. If no key exists, returns an empty string.

        Returns:
        str: A key with the lowest count, or an empty string if no key exists.
        """
        if self.head.next == self.tail:
            return ""  # No keys present
        return next(iter(self.head.next.keys))  # Return any key from the lowest frequency node


# Your AllOne object will be instantiated and called as such:
# obj = AllOne()
# obj.inc(key)
# obj.dec(key)
# param_3 = obj.getMaxKey()
# param_4 = obj.getMinKey()