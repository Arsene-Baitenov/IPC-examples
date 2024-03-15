## Shared memory example

Build:
```sh
./build.sh
```

Create shared memory area:
```sh
./shm create
```

Write message:
```sh
./shm write Hello!
```
Read message:
```sh
./shm read
```

Unlink shared memory area:
```sh
./shm unlink
```