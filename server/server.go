package main

import (
	"bufio"
	"fmt"
	"io/ioutil"
	"log"
	"net/http"
	"os"
	"strings"
)

var textToSend = "on"

func helloWorld(w http.ResponseWriter, r *http.Request) {
	if r.URL.Path != "/" {
		http.NotFound(w, r)
		return
	}
	switch r.Method {
	case "GET":
		for k, v := range r.URL.Query() {
			fmt.Printf("%s: %s\n", k, v)
		}
		w.Write([]byte(textToSend))
	case "POST":
		reqBody, err := ioutil.ReadAll(r.Body)
		if err != nil {
			log.Fatal(err)
		}

		fmt.Printf("\nReceived a POST request from: <%s>\n", reqBody)
	default:
		w.WriteHeader(http.StatusNotImplemented)
		w.Write([]byte(http.StatusText(http.StatusNotImplemented)))
	}

}

// Sets the data that will be returned on a get request
func readKB() {
	reader := bufio.NewReader(os.Stdin)

	for {
		strRead, _ := reader.ReadString('\n')
		textToSend = strings.TrimSuffix(strRead, "\n")
	}

}

func main() {
	fmt.Println("Server started")
	go readKB()
	http.HandleFunc("/", helloWorld)
	http.ListenAndServe(":80", nil)
}
