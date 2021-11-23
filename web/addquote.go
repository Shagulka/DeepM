package main

import (
	"bytes"
	"encoding/json"
	"io"
	"io/ioutil"
	"log"
	"net/http"
)

func addQuote(quote string) {
	client := &http.Client{}
	values := map[string]string{"rowid": "0", "text": quote}
	data, err := json.Marshal(values)
	req, err := http.NewRequest("POST", "https://g648e561ebb875c-db202111100919.adb.eu-amsterdam-1.oraclecloudapps.com/ords/admin/deepmtable/", bytes.NewBuffer(data))
	if err != nil {
		log.Fatal(err)
	}
	req.Header.Set("Content-Type", "application/json")
	resp, err := client.Do(req)
	if err != nil {
		log.Fatal(err)
	}
	defer func(Body io.ReadCloser) {
		err := Body.Close()
		if err != nil {
			log.Print(err)
		}
	}(resp.Body)
	bodyText, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		log.Fatal(err)
	}
	log.Printf("Отправлено: %s\n", bodyText)
}
