package main

import (
	"fmt"
	"log"
	"net/http"
	"net/http/httputil"
	"os"
)

func main() {
	if len(os.Args) < 2 {
		log.Fatal("Please provide a port number")
	}
	port := os.Args[1]
	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		// Log the incoming request
		requestDump, err := httputil.DumpRequest(r, true)
		if err != nil {
			fmt.Println(err)
		}
		fmt.Println("Received request from", r.RemoteAddr)
		fmt.Println(string(requestDump))

		// Send a response
		w.WriteHeader(http.StatusOK)
		fmt.Fprint(w, "Hello From Backend Server "+port)
		fmt.Println("Replied with a hello message")
	})

	fmt.Println("Backend server is running on http://localhost:" + port)
	log.Fatal(http.ListenAndServe(":"+port, nil))
}
