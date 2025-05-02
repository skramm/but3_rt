
# Identification des process utilisant une connection

Plusieurs outils:
netstat, ss, lsof

```
$ sudo netstat -ano -p tcp | grep NUM_PORT
```

Options:

-a, --all
       Show both listening and non-listening sockets.  With  the  --interfaces
       option, show interfaces that are not up

--numeric, -n
       Show  numerical addresses instead of trying to determine symbolic host,
       port or user names.

-l, --listening
       Show only listening sockets.  (These are omitted by default.)

