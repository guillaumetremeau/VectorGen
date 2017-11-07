#define CATCH_CONFIG_MAIN

#include "Catch/include/catch.hpp"
#include <cstring>
#include "VectorGen.hpp"

TEST_CASE ("Vecteur1") {
  const Vecteur v;

  REQUIRE ( v.capacity() >= 10 );
  REQUIRE ( v.size()     == 0  );
}


TEST_CASE ("Vecteur2" ) {
  Vecteur v(20);

  REQUIRE ( v.capacity() == 20 );
  REQUIRE ( v.size()     == 0  );
}

TEST_CASE ("Vecteur3" ) {
  Vecteur v(5);

  SECTION("ajout de quelques elements") {
    REQUIRE ( v.capacity() == 5 );

    for (int i=0; i<4; ++i)
      v.push_back(i*1.0);

    REQUIRE ( v.size()     == 4  );
  }

  SECTION("tableau un peu agrandi") {
    // on peut verifier que vecteur est bien un nouveau :-)
  REQUIRE ( v.capacity() == 5 );
    for (int i=0; i<6; ++i)
      v.push_back(i*1.0);

    REQUIRE ( v.capacity()  == 10 );
    REQUIRE ( v.size()      == 6  );
  }

  SECTION("on verifie les valeurs dans le vecteur") {
    for (int i=0; i<25; ++i)
      v.push_back(i*1.0);

    REQUIRE( v.capacity() ==  40 );
    REQUIRE( v.size()     ==  25 );

    for (int i=0; i<25; ++i)
      CHECK(v[i] == Approx(i*1.0+0.1));  // :-)
  }

  SECTION("on verifie les exceptions") {
    REQUIRE_THROWS_AS( v[-1] == 0, Vecteur::OutOfRangeException);
    REQUIRE_THROWS_AS( v [6] == 0, std::bad_alloc);  // :-)
   }
}
