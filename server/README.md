# Server

A Go program will be used as the backend application to receive the POST request on port 80. An Azure VM was setup with port 80 exposed. In this example, a binary was compiled for the Linux x64 server.

### Compiling
```bash
# Compile the GO program 
GOOS=linux go build -v server.go

# Send to the server
scp server user@X.X.X.X:.
```