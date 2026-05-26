package main

import (
	"fmt"
	"log"
	"net/http"
	"net/http/httputil"
	"net/url"
)

func main() {
	backendURL, err := url.Parse("http://localhost:8081")
	if err != nil {
		log.Fatalf("Failed to parse backend URL: %v", err)
	}

	proxy := httputil.NewSingleHostReverseProxy(backendURL)

	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		// Log the incoming request
		requestDump, err := httputil.DumpRequest(r, true)
		if err != nil {
			fmt.Println(err)
		}
		fmt.Println("Received request from", r.RemoteAddr)
		fmt.Println(string(requestDump))

		// Forward the request to the backend
		proxy.ServeHTTP(w, r)
	})

	fmt.Println("Load balancer is running on http://localhost:8080")
	log.Fatal(http.ListenAndServe(":8080", nil))
}
