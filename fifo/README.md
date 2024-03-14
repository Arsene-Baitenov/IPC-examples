## FIFO example

Build:
```sh
./build.sh
```

Open two terminals.

# First scenario
Create fifo and run reader process:
```sh
./create && ./read
```

Write message by using writer process:
```sh
./write Hello!
```
Or by using `echo`:
```sh
echo Hello >> /tmp/named_pipe
```

# First scenario
Create fifo and write message by using write process:
```sh
./create && ./write Hello!
```

Run reader process:
```sh
./read
```