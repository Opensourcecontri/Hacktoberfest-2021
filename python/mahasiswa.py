#!/usr/bin/env python3
# author   : akbar@kustirama.id

import requests, argparse, json

print ('''  	  			 
          codelatte.net
''')

parser = argparse.ArgumentParser()
parser.add_argument('-m', '--mahasiswa', required=True, help="Name/NIM")
args = parser.parse_args()

def mahasiswaDetail(keyword):
	print(keyword)

def mahasiswa(keyword):
	print('Searching for "' + keyword + '"\n')
	headers = {
		'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.114 Safari/537.36',
	}

	x = requests.get("https://api-frontend.kemdikbud.go.id/hit_mhs/" + keyword.replace(" ", "%20"), headers=headers, verify=False).text
	output = json.loads(x)
	
	for s in output['mahasiswa']:
		if "Cari kata kunci" in s['text']:
			print("Not found!")
		else:
			code = s['website-link'].split('/')[2]
			get_detail = requests.get("https://api-frontend.kemdikbud.go.id/detail_mhs/" + code, headers=headers).text
			details = json.loads(get_detail)
			detail = json.dumps(details['dataumum'])
			detail_data = json.loads(detail)
			
			if (keyword.isdecimal()):
				print("Name\t\t: " + detail_data['nm_pd'] + "\nNIPD\t\t: " + detail_data['nipd'] + "\nLembaga\t\t: " + detail_data['namapt'] + "\nJenjang\t\t: " + detail_data['namajenjang'] + "\nProdi\t\t: " + detail_data['namaprodi'] + "\nSemester Awal\t: " + detail_data['mulai_smt'][:-1] + "\nURL\t\t: https://pddikti.kemdikbud.go.id/data_mahasiswa/" + code + "\n")
			else:
				print("Name\t\t: " + detail_data['nm_pd'] + "\nNIPD\t\t: " + detail_data['nipd'] + "\nLembaga\t\t: " + detail_data['namapt'] + "\nJenjang\t\t: " + detail_data['namajenjang'] + "\nProdi\t\t: " + detail_data['namaprodi'] + "\nSemester Awal\t: " + detail_data['mulai_smt'][:-1] + "\nLulus\t\t: " + str(detail_data['ket_keluar']) + "\nTanggal Keluar\t: " + str(detail_data['tgl_keluar']) + "\nNo. Ijazah\t: " + str(detail_data['no_seri_ijazah']) + "\n")
	
if args.mahasiswa:
	mahasiswa(args.mahasiswa)
