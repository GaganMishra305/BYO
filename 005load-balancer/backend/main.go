package main

import (
	"fmt"
	"log"
	"net/http"
	"net/http/httputil"
)

func main() {
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
		fmt.Fprint(w, "Hello From Backend Server")
		fmt.Println("Replied with a hello message")
	})

	fmt.Println("Backend server is running on http://localhost:8081")
	log.Fatal(http.ListenAndServe(":8081", nil))
}
