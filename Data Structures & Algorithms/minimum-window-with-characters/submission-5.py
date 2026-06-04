class Solution:
    def addOrUpdateDict(self, freq, char):
        if char in freq:
            freq[char] += 1
        else:
            freq[char] = 1

    def removeOrDeleteFromDict(self, freq, char):
        freq[char] -= 1
        if freq[char] == 0:
            freq.pop(char)

    def isEqualOrSubset(self, freq1, freq2):
        if len(freq1) != len(freq2):
            return False
        else:
            for char in freq1:
                if freq1[char] > freq2[char]:
                    return False

        return True
    
    def minWindow(self, s: str, t: str) -> str:
        '''
        I will start from a position and keep iterating until
        there's one character in t for which freq in s exceeds freq in t
        '''

        start = 0
        end = 0

        lenS = len(s)

        freqT = {}

        for character in t:
            self.addOrUpdateDict(freqT, character)

        freqS = {}
        substrLength = lenS + 1

        resStart = -1
        resEnd = -1

        while end < lenS:
            currChar = s[end]

            if currChar in t:
                self.addOrUpdateDict(freqS, currChar)

                if self.isEqualOrSubset(freqT, freqS):
                    while s[start] not in freqS or freqS[s[start]] > freqT[s[start]]:
                        if s[start] in freqS:
                            freqS[s[start]] -= 1
                        start += 1

                    if substrLength > end-start+1:
                        resStart = start
                        resEnd = end
                        substrLength = resEnd-resStart+1

                    self.removeOrDeleteFromDict(freqS, s[start])
                    start += 1
            end += 1

        return "" if substrLength == lenS+1 else s[resStart:resEnd+1]
                



