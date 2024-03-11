// Copyright 2022
// By Dr. Rykalova
// Editted by Dr. Daly
// test.cpp for PS1a
// updated 5/12/2022

#include <iostream>
#include <string>

#include "FibLFSR.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(testStepInstr1) {
  FibLFSR l("1011011000110110");
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
}

BOOST_AUTO_TEST_CASE(testStepInstr2) {
  FibLFSR l2("1011011000110110");
  BOOST_REQUIRE_EQUAL(l2.generate(9), 51);
}

BOOST_AUTO_TEST_CASE(testInsertionOperator) {
  FibLFSR l3("1011011000110110");
  
  std::stringstream stringOutput;

  stringOutput << l3;

  // .str() return the string from stream buffer.
  BOOST_REQUIRE_EQUAL(stringOutput.str(), "1011011000110110");
}

BOOST_AUTO_TEST_CASE(testConstructor) {
  FibLFSR l4("1011011000110110");

  std::string stringTest = l4.getString();

  // stringTest return the private string data member from FibLFSR class.
  BOOST_REQUIRE_EQUAL(stringTest, "1011011000110110");
}