# encoding: utf-8


# lesson2

# comment
print "Hello World"

=begin
ブロックコメント
=end

print "h2"

# lesson3

print "h2" # 普通に表示
puts "Hello world, again" # 改行付きで表示
p "Hello world 3" # オブジェクト型がわかるように表示 (dump)

print "hoge", "hage", "moge" # 複数指定可能
puts "hoge", "hage", "moge" # 複数指定可能

# lesson4
# 変数と定数

x = 10  # 変数
p x

#end = 5  # 予約語は変数に使えない

EMAIL = "a.shigeru@gmail.com"  # 全部大文字だと定数
# EMAIL = "hoge"; # 上書きはエラー

puts EMAIL


# lesson5 オブジェクト

p "hello".length

# lesson6 クラスとインスタンス

# @see http://www.ruby-doc.org/core-2.0.0/String.html


# lesson7 数値オブジェクト

p 10.1

p Rational(2, 3);

p 5 ** 2
p 5 % 2

p Rational(2, 3) + Rational(5, 6)

# lesson8 数値オブジェクトのメソッド

p 10.5.to_i
p 10.5.to_r
p 10.5.round
p 10.5.ceil
p 10.5.floor
p rand(100)
p Math.sqrt(2);


# lesson9 文字列オブジェクト

x = "hello" # 変数、特殊文字は展開
y = 'hello' # 変数、特殊文字を展開しない

puts "hello\nworld"


name = "tabugchi"
puts "my name is #{name}"

puts "こんにちは"

# lesson10 文字列のメソッド

p "hello".upcase
p "hello".reverse
p "hello".index("l")
p "hello".include?("o");


# lesson11 破壊的メソッド

s = "hello"
s1 = s.upcase # 安全なヤツ
p s # "hello"

s1 = s.upcase! # 破壊的
p s # ""
