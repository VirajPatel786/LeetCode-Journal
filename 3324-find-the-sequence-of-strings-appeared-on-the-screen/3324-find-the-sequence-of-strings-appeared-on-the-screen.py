class Solution:
    def stringSequence(self, target: str) -> List[str]:
        result = list()
        i = 0
        str_to_append = ""
        while (i < len(target)):
            char = 'a'
            while (True):
                if char != target[i]:
                    result.append(str_to_append + char)
                    char = chr(ord(char) + 1)
                else:
                    str_to_append += char
                    result.append(str_to_append)
                    break
            i += 1
        return result