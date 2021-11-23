package main

import (
	"io/ioutil"
	"log"
	"net/http"
)

func handler(_ http.ResponseWriter, r *http.Request) {
	switch r.Method {
	case "POST":
		body, _ := ioutil.ReadAll(r.Body)
		log.Printf("Цитата %s", body)
		addQuote(string(body))
	}
}
