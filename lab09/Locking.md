# Scenarios

## 1
```
lock(A)
lock(B)
....
unlock(B)
unlock(A)
```

## 2
```
lock(A)
lock(B)
...
unlock(A)
unlock(B)
```

## 2b
```
lock(A)
lock(B)
...
unlock(A)
func();
unlock(B)

func():
lock(A)
...
unlock(A)
```

## 3
```
t1:
lock(A)
lock(B)
...
unlock(B)
unlock(A)

t2:
lock(B)
lock(A)
...
unlock(A)
unlock(B)
```
