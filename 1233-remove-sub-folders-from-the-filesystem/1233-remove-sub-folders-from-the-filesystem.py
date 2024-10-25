from typing import List

class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        """
        Remove all sub-folders from the given list of folder paths.

        Parameters:
        folder (List[str]): List of folder paths.

        Returns:
        List[str]: List of folder paths without sub-folders.
        """
        # Sort folders lexicographically
        folder.sort()
        result = []
        
        for path in folder:
            # If the current path is not a sub-folder of the last path in result
            if not result or not path.startswith(result[-1] + '/'):
                result.append(path)
                
        return result
