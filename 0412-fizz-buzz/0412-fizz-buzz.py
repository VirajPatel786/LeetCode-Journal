class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        result = []
        for i in range(1, n+1):
            string_to_append = ""
            if ((i%3) == 0):
                string_to_append += 'Fizz'
            if ((i%5) == 0):
                string_to_append += 'Buzz'
            if string_to_append == "":
                string_to_append += str(i)
            result.append(string_to_append)
        return result

        