def mergeSort(list):
    if len(list) > 1:
        mid = len(list)//2
        leftSide = list[:mid]
        rightSide = list[mid:]

        mergeSort(leftSide)
        mergeSort(rightSide)

        i=j=k = 0
        while i < len(leftSide) and j < len(rightSide):
            if leftSide[i] < rightSide[j]:
                list[k] = leftSide[i]
                i = i+1
            else:
                list[k] = rightSide[j]
                j = j+1
            k = k+1

        while i < len(leftSide):
            list[k] = leftSide[i]
            i = i+1
            k = k+1

        while j < len(rightSide):
            list[k] = rightSide[j]
            j = j+1
            k = k+1
