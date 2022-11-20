import hashlib
username = "digestman"
password = "wakarimasen"
http_method = "GET"
uri = "/digest/index.html"
nonce = "8a42eVmhBQA=aa5b69008256e4c8cebd2c9e6c894ee563e16df2"
cnonce = "50e56772e791093b"
realm = "digest"
nc = "00000001"
qop = "auth"
A1 = username + realm + password
A2 = http_method + ":" + uri
md5_A1 = "ec3debbd6af692e932778826e283ac5c"
md5_A2 = hashlib.md5(A2).hexdigest()
response = hashlib.md5(":".join([md5_A1, nonce, nc, cnonce, qop, md5_A2])).hexdigest()
print(response)
