class Jar:
    def __init__(self, capacity=12):
        if capacity < 0:
            raise ValueError('Wrong capacity')
        self._capacity = capacity
        self._size = 0

    def __str__(self):
        return self.size*'o'

    def deposit(self, n):
        if self.size + n > self.capacity:
            raise ValueError('exceeds capacity')
        if n > self.capacity:
            raise ValueError('exceeds capacity')
        self._size += n

    def withdraw(self, n):
        if self.size < n:
            raise ValueError('not enough cookies')
        self._size -= n

    @property
    def capacity(self):
        return self._capacity

    @property
    def size(self):
        return self._size


jar = Jar()
print(str(jar.capacity))
print(str(jar))