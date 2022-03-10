// Dr. Rykalova
// test.cpp for PS1a
// updated 1/31/2020

#include <iostream>
#include <string>

#include "FibLFSR.h"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_CASE(sixteenBitsThreeTaps) {

  FibLFSR l("1011011000110110");
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);

  FibLFSR l2("1011011000110110");
  BOOST_REQUIRE(l2.generate(9)== 51);
}

//test if contructor works properly for 10 bits
BOOST_AUTO_TEST_CASE( constructors_test ){
  FibLFSR l("1011011000"),l2("01"),l3("111"),l4("0101"),l5("00000");
  BOOST_CHECK_EQUAL(l.getSize(),10);
  BOOST_CHECK_EQUAL(l2.getSize(),2);
  BOOST_CHECK_EQUAL(l3.getSize(),3);
  BOOST_CHECK_EQUAL(l4.getSize(),4);
  BOOST_CHECK_EQUAL(l5.getSize(),5);
}

//test if generate function works correctly
BOOST_AUTO_TEST_CASE(sixteenBitsThreeTapsGenerate){
  FibLFSR l("1011011000110110");
  BOOST_REQUIRE(l.generate(5)== 3);
  BOOST_REQUIRE(l.generate(5)== 6);
  BOOST_REQUIRE(l.generate(5)== 14);
  BOOST_REQUIRE(l.generate(5)== 24);
  BOOST_REQUIRE(l.generate(5)== 1);
  BOOST_REQUIRE(l.generate(5)== 13);
  BOOST_REQUIRE(l.generate(5)== 28);


}

