class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        nameIndex = {name: idx for idx, name in enumerate(list1)}
        ansIndexSummary = None
        ansRestaurants = []
        for idx, name in enumerate(list2):
            if name in nameIndex:
                indexSummary = nameIndex[name] + idx
                if ansIndexSummary is None or ansIndexSummary > indexSummary:
                    ansIndexSummary = indexSummary
                    ansRestaurants.clear()
                    ansRestaurants.append(name)
                elif ansIndexSummary == indexSummary:
                    ansRestaurants.append(name)
        return ansRestaurants
