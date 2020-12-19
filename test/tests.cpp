int b = 3;
  MyString c;
  c = a * b;
  EXPECT_EQ("123123123", c.get());
  EXPECT_STREQ("123123123", c.get());
}

TEST(MyStringTest, test9) {
