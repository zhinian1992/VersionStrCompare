#include "pch.h"

TEST(VersionTest, HandlesToString) {
	Version ver("1.1.1");
	EXPECT_EQ(ver.to_string(),"1.1.1");
}

TEST(VersionTest, HandleParse) {
	Version ver;
	string str = "1.1.1";
	EXPECT_EQ(true, ver.Parse(str));
}

TEST(VersionTest, compare) {
	Version ver0("1.1");
	Version ver1("1.1.1");
	Version ver2("1.1.1");
	Version ver3("1.1.11");
	Version ver4("1.2.12");
	Version ver5("1.3.11");
	Version ver6("1.2.14");
	Version ver7("3.2.14");
	Version ver8("4.2.11");
	Version ver9("5.3.1");
	Version ver10("6.2.15");
	Version ver11("7.1.1");
	Version ver12("8.4.1");

	//¹æÔò²»·û
	EXPECT_EQ(3, ver0.compare(ver1));
	/* = = =*/
	EXPECT_EQ(0, ver1.compare(ver2));
	/* = = >*/
	EXPECT_EQ(1, ver3.compare(ver2));
	/* = = <*/
	EXPECT_EQ(2, ver2.compare(ver3));
	/* = > =*/
	EXPECT_EQ(1, ver4.compare(ver3));
	/* = > >*/
	EXPECT_EQ(1, ver4.compare(ver2));
	/* = > <*/
	EXPECT_EQ(1, ver5.compare(ver4));
	/* = < =*/
	EXPECT_EQ(2, ver3.compare(ver5));
	/* = < >*/
	EXPECT_EQ(2, ver6.compare(ver5));
	/* = < <*/
	EXPECT_EQ(2, ver3.compare(ver6));
	/* > = =*/
	EXPECT_EQ(1, ver7.compare(ver6));
	/* > = >*/
	EXPECT_EQ(1, ver7.compare(ver4));
	/* > = <*/
	EXPECT_EQ(1, ver8.compare(ver7));
	/* > > =*/
	EXPECT_EQ(1, ver8.compare(ver3));
	/* > > >*/
	EXPECT_EQ(1, ver8.compare(ver2));
	/* > > <*/
	EXPECT_EQ(1, ver9.compare(ver8));
	/* > < =*/
	EXPECT_EQ(1, ver8.compare(ver5));
	/* > < >*/
	EXPECT_EQ(1, ver10.compare(ver9));
	/* > < <*/
	EXPECT_EQ(1, ver11.compare(ver10));
	/* < = =*/
	EXPECT_EQ(2, ver2.compare(ver11));
	/* < = >*/
	EXPECT_EQ(2, ver3.compare(ver11));
	/* < = <*/
	EXPECT_EQ(2, ver4.compare(ver10));
	/* < > =*/
	EXPECT_EQ(2, ver9.compare(ver11));
	/* < > >*/
	EXPECT_EQ(2, ver5.compare(ver11));
	/* < > <*/
	EXPECT_EQ(2, ver5.compare(ver10));
	/* < < =*/
	EXPECT_EQ(2, ver2.compare(ver9));
	/* < < >*/
	EXPECT_EQ(2, ver10.compare(ver12));
	/* < < <*/
	EXPECT_EQ(2, ver2.compare(ver10));

}