from typing import TypeVar, Generic, List
T = TypeVar('T')

class Stack(Generic[T]) :

    def __init__(self) -> None :
        self._container: List[T] = []

    def push (self, item: T) -> None:
        self._container.append(item)

    def pop(self) -> T:
        return self._container.pop()

    def __repr__(self) -> str: #print in the tower
        return repr(self._container)

num: int = 6
a: Stack[int] = Stack()
b: Stack[int] = Stack()
c: Stack[int] = Stack()
for i in range(1, num+1):
    a.push(i)

def hanoi(begin: Stack[int], end: Stack[int], temp: Stack[int], n:int) -> None :
    if n == 1:
        end.push(begin.pop())
    else:
        hanoi(begin, temp, end, n-1)
        hanoi(begin, end, temp, 1)
        hanoi(temp, end, begin, n-1)

if __name__ == "__main__":
    hanoi(a, c, b, num)
    print(a)
    print(b)
    print(c)
