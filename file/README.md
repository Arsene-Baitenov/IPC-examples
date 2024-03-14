## File as fifo example

Create fifo file:
```sh
touch ch.txt
```

Open two terminals.

Run "reader of fifo file" process in the first terminal:
```sh
tail -f ch.txt
```

"Write" in fifo file:
```sh
echo "Hi!" >> ch.txt
``` 