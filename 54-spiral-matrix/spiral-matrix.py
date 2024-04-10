class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        lst=[]
        sti=0
        endi=len(matrix)-1

        stj=0
        endj=len(matrix[0])-1

        # if sti==endi:
        #     for j in range(stj,endj+1):
        #         lst.append(matrix[sti][j])
        #     return lst
        # elif stj==endj:
        #     for i in range(sti,endi+1):
        #         lst.append(matrix[i][endj])
        #     return lst


        
        while(sti<endi) and (stj < endj):
            for j in range(stj,endj+1):
                lst.append(matrix[sti][j])
            for i in range(sti+1,endi+1):
                lst.append(matrix[i][endj])
            for j in range(endj-1,stj-1,-1):
                lst.append(matrix[endi][j])
            for i in range(endi-1,sti,-1):
                lst.append(matrix[i][stj])

            sti+=1
            stj+=1
            endi-=1
            endj-=1

        if sti==endi:
            for j in range(stj,endj+1):
                lst.append(matrix[sti][j])
        elif stj==endj:
            for i in range(sti,endi+1):
                lst.append(matrix[i][endj])

        return lst