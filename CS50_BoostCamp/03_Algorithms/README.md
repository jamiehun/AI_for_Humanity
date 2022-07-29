## Big O
|    |   |
|----|---|
|O(n^2) | bubble sort, selection sort|
|O(nlog n) | merge sort
|O(n) | linear search
|O(log n) | binary search
|O(1) | 
|    
## Omega
|    |   |
|--|---|
|Omega(n^2) | bubble sort, selection sort
|Omega(n log n) | merge sort
|Omega(n) | bubble sort(better)
|Omega(log n) |
|Omega(1) | linear search, selection search
|    

## Theta (Big O == Omega)
|    |   |
|--|---|
| Theta(n^2) | selection sort
| Theta(n log n) | merge sort
| Theta(n) |
| Theta(log n) |
| Theta(1) |
|

</br>



# 배열
- 배열은 한 자료형의 여러 값들이 메모리 상에 모여있는 구조로
- 컴퓨터는 이 값들에 대해 접근할 때 인덱스 하나하나를 접근함

## Linear Search (선형 검색)
- 배열의 인덱스를 처음부터 하나씩 증가시키면서 방문하여 값이 속하는지 검사
- pseudo code
    ```c
    /*
    for i from 0 to n-1
        if i'th element is 50
        Return True
    Return False
    */
    ```

<br>

## Binary Search (이진 검색)
- 배열이 정렬되어 있다면 배열 중간 인덱스부터 시작하여 찾고자 하는 값과 비교하여 그보다 작은 인덱스 또는 큰 인덱스로 이동을 반복
- pseudo code
    ```c
    /*
    If no items
        Return False
    If middle item is 50
        Return True
    Else if 50 < middle item
        Search left half
    Else if 50 > middle item
        Search right half
    */
    ```
## Big O
- 'on the order of~', '~만큼의 정도로 커지는'
- O(n)이나 O(n/2)는 같은 값으로 볼 수 있음
- 알고리즘을 수행하는데 필요한 시간의 상한선, 최악의 경우 필요한 상한선
    - Linear Search : O(N)
    - Binary Search : O(logN)

## Big Omega
- 빅오와 반대 (최선의 경우 필요한 하한선)

</br>

---

</br>

# 정렬
## Bubble Sort (버블 정렬)
- 두 개의 인접한 자료 값을 비교하면서 위치를 교환하는 방식으로 정렬하는 방법
- pseudo code
    ```c
    /*
    Repeat n-1 times
        for i from 0 to n-2
            If i'th and i+1'th elements out of order
                Swap them
    */
    ```

- Better pseudo code (Omega(n))
    ```c
    /*
    Repeat until no swaps
        for i from 0 to n-2
            If i'th and i+1'th elements out of order
                Swap them
    */
    ```

- Big O : (n-1) x (n-1) => O(n^2)
- Omega : (n-1) x (n-1) => Omega(n^2)

<br>

## Selection Sort (선택 정렬)
- 배열 중의 가장 작은 수를 찾아 첫번째 위치의 수와 교환해주는 방식 (혹은 반대)
- pseudo code
    ```c
    /*
    For i from 0 to n-1
        Find smallest item between i'th item and last item
        Swap smallest item with i'th item
    */
   ```
- Big O : n + (n-1) + .. + 1 = n(n+1)/2 => O(n^2)
- Omega : Omega(n^2)

<br>

---
<br>

# 재귀 (Recursion)
- 함수가 본인 스스로를 호출해서 사용하는 것
- 스택 : 함수를 위한 메모리가 계속되서 할당되는 것
- pseudo code
    ```c
    /*
    Pick up phone book
    Open to middle of phone book
    Look at page
    If Smith is on page
        Call Mike
    Else if Smith is earlier in book
        Search left half of book
    Else if Smith is later in book
        Search right half of book
    Else
        Quit
    */
   ```

<br>   

## Merge Sort (병합 정렬)
- 원소가 한 개가 될 때까지 계속해서 반으로 나누다가 다시 합쳐나가며 정렬하는 방식
- pseudo code
  ```c
    /*
    If only one item
        Return
    Else
        Sort left half of items   // Step 1
        Sort right half of items  // Step 2
        Merge sorted halves       // Step 3
    */
   ```

- Big O : n log(n)