# 暗号化
openssl rsautl -pubin -inkey public.key -in secret.txt -encrypt -out secret.rsa.txt
# 複合化
openssl rsautl -inkey private.key -in secret.rsa.txt -decrypt -out secret.txt