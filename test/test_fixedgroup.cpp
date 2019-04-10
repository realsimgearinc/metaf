/*
* Copyright (C) 2018-2019 Nick Naumenko (https://gitlab.com/nnaumenko)
* All rights reserved.
* This software may be modified and distributed under the terms
* of the MIT license. See the LICENSE file for details.
*/

#include "gtest/gtest.h"
#include "metaf.h"

TEST(FixedGroup, parseMetar) {
	static const char gs[] = "METAR";

	auto fg = metaf::FixedGroup::parse(gs, metaf::ReportPart::HEADER);
	ASSERT_TRUE(fg.has_value());
	EXPECT_EQ(fg->type(), metaf::FixedGroup::Type::METAR);

	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::UNKNOWN).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::METAR).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::TAF).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::RMK).has_value());
}

TEST(FixedGroup, parseSpeci) {
	static const char gs[] = "SPECI";

	auto fg = metaf::FixedGroup::parse(gs, metaf::ReportPart::HEADER);
	ASSERT_TRUE(fg.has_value());
	EXPECT_EQ(fg->type(), metaf::FixedGroup::Type::SPECI);

	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::UNKNOWN).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::METAR).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::TAF).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::RMK).has_value());
}

TEST(FixedGroup, parseTaf) {
	static const char gs[] = "TAF";

	auto fg = metaf::FixedGroup::parse(gs, metaf::ReportPart::HEADER);
	ASSERT_TRUE(fg.has_value());
	EXPECT_EQ(fg->type(), metaf::FixedGroup::Type::TAF);

	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::UNKNOWN).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::METAR).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::TAF).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::RMK).has_value());
}

TEST(FixedGroup, parseAmd) {
	static const char gs[] = "AMD";
	auto fg = metaf::FixedGroup::parse(gs, metaf::ReportPart::HEADER);
	ASSERT_TRUE(fg.has_value());
	EXPECT_EQ(fg->type(), metaf::FixedGroup::Type::AMD);

	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::UNKNOWN).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::METAR).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::TAF).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::RMK).has_value());
}

TEST(FixedGroup, parseNil) {
	static const char gs[] = "NIL";
	static const auto type = metaf::FixedGroup::Type::NIL;

	auto fg1 = metaf::FixedGroup::parse(gs, metaf::ReportPart::HEADER);
	ASSERT_TRUE(fg1.has_value());
	EXPECT_EQ(fg1->type(), type);

	auto fg2 = metaf::FixedGroup::parse(gs, metaf::ReportPart::METAR);
	ASSERT_TRUE(fg2.has_value());
	EXPECT_EQ(fg2->type(), type);

	auto fg3 = metaf::FixedGroup::parse(gs, metaf::ReportPart::TAF);
	ASSERT_TRUE(fg3.has_value());
	EXPECT_EQ(fg3->type(), type);

	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::UNKNOWN).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::RMK).has_value());
}

TEST(FixedGroup, parseCnl) {
	static const char gs[] = "CNL";
	static const auto type = metaf::FixedGroup::Type::CNL;

	auto fg1 = metaf::FixedGroup::parse(gs, metaf::ReportPart::HEADER);
	ASSERT_TRUE(fg1.has_value());
	EXPECT_EQ(fg1->type(), type);

	auto fg2 = metaf::FixedGroup::parse(gs, metaf::ReportPart::METAR);
	ASSERT_TRUE(fg2.has_value());
	EXPECT_EQ(fg2->type(), type);

	auto fg3 = metaf::FixedGroup::parse(gs, metaf::ReportPart::TAF);
	ASSERT_TRUE(fg3.has_value());
	EXPECT_EQ(fg3->type(), type);

	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::UNKNOWN).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::RMK).has_value());
}

TEST(FixedGroup, parseCor) {
	static const char gs[] = "COR";
	static const auto type = metaf::FixedGroup::Type::COR;

	auto fg1 = metaf::FixedGroup::parse(gs, metaf::ReportPart::HEADER);
	ASSERT_TRUE(fg1.has_value());
	EXPECT_EQ(fg1->type(), type);

	auto fg2 = metaf::FixedGroup::parse(gs, metaf::ReportPart::METAR);
	ASSERT_TRUE(fg2.has_value());
	EXPECT_EQ(fg2->type(), type);

	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::UNKNOWN).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::TAF).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::RMK).has_value());
}

TEST(FixedGroup, parseAuto) {
	static const char gs[] = "AUTO";

	auto fg = metaf::FixedGroup::parse(gs, metaf::ReportPart::METAR);
	ASSERT_TRUE(fg.has_value());
	EXPECT_EQ(fg->type(), metaf::FixedGroup::Type::AUTO);

	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::UNKNOWN).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::HEADER).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::TAF).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::RMK).has_value());
}

TEST(FixedGroup, parseSnoclo) {
	static const char gs[] = "SNOCLO";

	auto fg = metaf::FixedGroup::parse(gs, metaf::ReportPart::METAR);
	ASSERT_TRUE(fg.has_value());
	EXPECT_EQ(fg->type(), metaf::FixedGroup::Type::R_SNOCLO);

	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::UNKNOWN).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::HEADER).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::TAF).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::RMK).has_value());
}

TEST(FixedGroup, parseRsnoclo) {
	static const char gs[] = "R/SNOCLO";

	auto fg = metaf::FixedGroup::parse(gs, metaf::ReportPart::METAR);
	ASSERT_TRUE(fg.has_value());
	EXPECT_EQ(fg->type(), metaf::FixedGroup::Type::R_SNOCLO);

	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::UNKNOWN).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::HEADER).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::TAF).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::RMK).has_value());
}

TEST(FixedGroup, parseCavok) {
	static const char gs[] = "CAVOK";
	static const auto type = metaf::FixedGroup::Type::CAVOK;

	auto fg1 = metaf::FixedGroup::parse(gs, metaf::ReportPart::METAR);
	ASSERT_TRUE(fg1.has_value());
	EXPECT_EQ(fg1->type(), type);

	auto fg2 = metaf::FixedGroup::parse(gs, metaf::ReportPart::TAF);
	ASSERT_TRUE(fg2.has_value());
	EXPECT_EQ(fg2->type(), type);

	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::UNKNOWN).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::HEADER).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::RMK).has_value());
}

TEST(FixedGroup, parseNsw) {
	static const char gs[] = "NSW";
	static const auto type = metaf::FixedGroup::Type::NSW;

	auto fg1 = metaf::FixedGroup::parse(gs, metaf::ReportPart::METAR);
	ASSERT_TRUE(fg1.has_value());
	EXPECT_EQ(fg1->type(), type);

	auto fg2 = metaf::FixedGroup::parse(gs, metaf::ReportPart::TAF);
	ASSERT_TRUE(fg2.has_value());
	EXPECT_EQ(fg2->type(), type);

	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::UNKNOWN).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::HEADER).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::RMK).has_value());
}

TEST(FixedGroup, parseRmk) {
	static const char gs[] = "RMK";
	static const auto type = metaf::FixedGroup::Type::RMK;

	auto fg1 = metaf::FixedGroup::parse(gs, metaf::ReportPart::METAR);
	ASSERT_TRUE(fg1.has_value());
	EXPECT_EQ(fg1->type(), type);

	auto fg2 = metaf::FixedGroup::parse(gs, metaf::ReportPart::TAF);
	ASSERT_TRUE(fg2.has_value());
	EXPECT_EQ(fg2->type(), type);

	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::UNKNOWN).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::HEADER).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::RMK).has_value());
}

TEST(FixedGroup, parseMaintenanceIndicator) {
	static const char gs[] = "$";
	static const auto type = metaf::FixedGroup::Type::MAINTENANCE_INDICATOR;

	auto fg1 = metaf::FixedGroup::parse(gs, metaf::ReportPart::UNKNOWN);
	ASSERT_TRUE(fg1.has_value());
	EXPECT_EQ(fg1->type(), type);

	auto fg2 = metaf::FixedGroup::parse(gs, metaf::ReportPart::HEADER);
	ASSERT_TRUE(fg2.has_value());
	EXPECT_EQ(fg2->type(), type);

	auto fg3 = metaf::FixedGroup::parse(gs, metaf::ReportPart::METAR);
	ASSERT_TRUE(fg3.has_value());
	EXPECT_EQ(fg3->type(), type);

	auto fg4 = metaf::FixedGroup::parse(gs, metaf::ReportPart::TAF);
	ASSERT_TRUE(fg4.has_value());
	EXPECT_EQ(fg4->type(), type);

	auto fg5 = metaf::FixedGroup::parse(gs, metaf::ReportPart::RMK);
	ASSERT_TRUE(fg5.has_value());
	EXPECT_EQ(fg5->type(), type);

}

TEST(FixedGroup, parseWsconds) {
	static const char gs[] = "WSCONDS";
	static const auto type = metaf::FixedGroup::Type::WSCONDS;

	auto fg = metaf::FixedGroup::parse(gs, metaf::ReportPart::TAF);
	ASSERT_TRUE(fg.has_value());
	EXPECT_EQ(fg->type(), type);

	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::UNKNOWN).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::HEADER).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::METAR).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::RMK).has_value());
}

TEST(FixedGroup, parseAo1) {
	static const char gs[] = "AO1";
	static const auto type = metaf::FixedGroup::Type::AO1;

	auto fg = metaf::FixedGroup::parse(gs, metaf::ReportPart::RMK);
	ASSERT_TRUE(fg.has_value());
	EXPECT_EQ(fg->type(), type);

	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::UNKNOWN).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::HEADER).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::METAR).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::TAF).has_value());
}

TEST(FixedGroup, parseAo2) {
	static const char gs[] = "AO2";
	static const auto type = metaf::FixedGroup::Type::AO2;

	auto fg = metaf::FixedGroup::parse(gs, metaf::ReportPart::RMK);
	ASSERT_TRUE(fg.has_value());
	EXPECT_EQ(fg->type(), type);

	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::UNKNOWN).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::HEADER).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::METAR).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::TAF).has_value());
}

TEST(FixedGroup, parseNospeci) {
	static const char gs[] = "NOSPECI";
	static const auto type = metaf::FixedGroup::Type::NOSPECI;

	auto fg = metaf::FixedGroup::parse(gs, metaf::ReportPart::RMK);
	ASSERT_TRUE(fg.has_value());
	EXPECT_EQ(fg->type(), type);

	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::UNKNOWN).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::HEADER).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::METAR).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::TAF).has_value());
}

TEST(FixedGroup, parsePresfr) {
	static const char gs[] = "PRESFR";
	static const auto type = metaf::FixedGroup::Type::PRESFR;

	auto fg = metaf::FixedGroup::parse(gs, metaf::ReportPart::RMK);
	ASSERT_TRUE(fg.has_value());
	EXPECT_EQ(fg->type(), type);

	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::UNKNOWN).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::HEADER).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::METAR).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::TAF).has_value());
}

TEST(FixedGroup, parsePresrr) {
	static const char gs[] = "PRESRR";
	static const auto type = metaf::FixedGroup::Type::PRESRR;

	auto fg = metaf::FixedGroup::parse(gs, metaf::ReportPart::RMK);
	ASSERT_TRUE(fg.has_value());
	EXPECT_EQ(fg->type(), type);

	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::UNKNOWN).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::HEADER).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::METAR).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::TAF).has_value());
}

TEST(FixedGroup, parseRvrno) {
	static const char gs[] = "RVRNO";
	static const auto type = metaf::FixedGroup::Type::RVRNO;

	auto fg = metaf::FixedGroup::parse(gs, metaf::ReportPart::RMK);
	ASSERT_TRUE(fg.has_value());
	EXPECT_EQ(fg->type(), type);

	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::UNKNOWN).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::HEADER).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::METAR).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::TAF).has_value());
}

TEST(FixedGroup, parsePwino) {
	static const char gs[] = "PWINO";
	static const auto type = metaf::FixedGroup::Type::PWINO;

	auto fg = metaf::FixedGroup::parse(gs, metaf::ReportPart::RMK);
	ASSERT_TRUE(fg.has_value());
	EXPECT_EQ(fg->type(), type);

	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::UNKNOWN).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::HEADER).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::METAR).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::TAF).has_value());
}

TEST(FixedGroup, parsePno) {
	static const char gs[] = "PNO";
	static const auto type = metaf::FixedGroup::Type::PNO;

	auto fg = metaf::FixedGroup::parse(gs, metaf::ReportPart::RMK);
	ASSERT_TRUE(fg.has_value());
	EXPECT_EQ(fg->type(), type);

	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::UNKNOWN).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::HEADER).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::METAR).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::TAF).has_value());
}

TEST(FixedGroup, parseFzrano) {
	static const char gs[] = "FZRANO";
	static const auto type = metaf::FixedGroup::Type::FZRANO;

	auto fg = metaf::FixedGroup::parse(gs, metaf::ReportPart::RMK);
	ASSERT_TRUE(fg.has_value());
	EXPECT_EQ(fg->type(), type);

	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::UNKNOWN).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::HEADER).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::METAR).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::TAF).has_value());
}

TEST(FixedGroup, parseTsno) {
	static const char gs[] = "TSNO";
	static const auto type = metaf::FixedGroup::Type::TSNO;

	auto fg = metaf::FixedGroup::parse(gs, metaf::ReportPart::RMK);
	ASSERT_TRUE(fg.has_value());
	EXPECT_EQ(fg->type(), type);

	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::UNKNOWN).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::HEADER).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::METAR).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::TAF).has_value());
}

TEST(FixedGroup, parseSlpno) {
	static const char gs[] = "SLPNO";
	static const auto type = metaf::FixedGroup::Type::SLPNO;

	auto fg = metaf::FixedGroup::parse(gs, metaf::ReportPart::RMK);
	ASSERT_TRUE(fg.has_value());
	EXPECT_EQ(fg->type(), type);

	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::UNKNOWN).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::HEADER).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::METAR).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse(gs, metaf::ReportPart::TAF).has_value());
}

TEST(FixedGroup, parseOther) {
	EXPECT_FALSE(metaf::FixedGroup::parse("", metaf::ReportPart::HEADER).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse("METAF", metaf::ReportPart::HEADER).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse("META", metaf::ReportPart::HEADER).has_value());
	EXPECT_FALSE(metaf::FixedGroup::parse("MMETAR", metaf::ReportPart::HEADER).has_value());
}

TEST(FixedGroup, isValid) {
	const auto fg1 = metaf::FixedGroup::parse("METAR", metaf::ReportPart::HEADER);
	ASSERT_TRUE(fg1.has_value());
	EXPECT_TRUE(fg1->isValid());
	
	const auto fg2 = metaf::FixedGroup::parse("SPECI", metaf::ReportPart::HEADER);
	ASSERT_TRUE(fg2.has_value());
	EXPECT_TRUE(fg2->isValid());
	
	const auto fg3 = metaf::FixedGroup::parse("TAF", metaf::ReportPart::HEADER);
	ASSERT_TRUE(fg3.has_value());
	EXPECT_TRUE(fg3->isValid());

	const auto fg4 = metaf::FixedGroup::parse("AMD", metaf::ReportPart::HEADER);
	ASSERT_TRUE(fg4.has_value());
	EXPECT_TRUE(fg4->isValid());

	const auto fg5 = metaf::FixedGroup::parse("NIL", metaf::ReportPart::HEADER);
	ASSERT_TRUE(fg5.has_value());
	EXPECT_TRUE(fg5->isValid());

	const auto fg6 = metaf::FixedGroup::parse("CNL", metaf::ReportPart::HEADER);
	ASSERT_TRUE(fg6.has_value());
	EXPECT_TRUE(fg6->isValid());

	const auto fg7 = metaf::FixedGroup::parse("COR", metaf::ReportPart::HEADER);
	ASSERT_TRUE(fg7.has_value());
	EXPECT_TRUE(fg7->isValid());
	
	const auto fg8 = metaf::FixedGroup::parse("AUTO", metaf::ReportPart::METAR);
	ASSERT_TRUE(fg8.has_value());
	EXPECT_TRUE(fg8->isValid());
	
	const auto fg9 = metaf::FixedGroup::parse("R/SNOCLO", metaf::ReportPart::METAR);
	ASSERT_TRUE(fg9.has_value());
	EXPECT_TRUE(fg9->isValid());

	const auto fg10 = metaf::FixedGroup::parse("CAVOK", metaf::ReportPart::METAR);
	ASSERT_TRUE(fg10.has_value());
	EXPECT_TRUE(fg10->isValid());

	const auto fg11 = metaf::FixedGroup::parse("NSW", metaf::ReportPart::METAR);
	ASSERT_TRUE(fg11.has_value());
	EXPECT_TRUE(fg11->isValid());

	const auto fg12 = metaf::FixedGroup::parse("RMK", metaf::ReportPart::METAR);
	ASSERT_TRUE(fg12.has_value());
	EXPECT_TRUE(fg12->isValid());

	const auto fg13 = metaf::FixedGroup::parse("WSCONDS", metaf::ReportPart::TAF);
	ASSERT_TRUE(fg13.has_value());
	EXPECT_TRUE(fg13->isValid());

	const auto fg14 = metaf::FixedGroup::parse("AO1", metaf::ReportPart::RMK);
	ASSERT_TRUE(fg14.has_value());
	EXPECT_TRUE(fg14->isValid());

	const auto fg15 = metaf::FixedGroup::parse("AO2", metaf::ReportPart::RMK);
	ASSERT_TRUE(fg15.has_value());
	EXPECT_TRUE(fg15->isValid());

	const auto fg16 = metaf::FixedGroup::parse("NOSPECI", metaf::ReportPart::RMK);
	ASSERT_TRUE(fg16.has_value());
	EXPECT_TRUE(fg16->isValid());

	const auto fg17 = metaf::FixedGroup::parse("PRESFR", metaf::ReportPart::RMK);
	ASSERT_TRUE(fg17.has_value());
	EXPECT_TRUE(fg17->isValid());

	const auto fg18 = metaf::FixedGroup::parse("PRESRR", metaf::ReportPart::RMK);
	ASSERT_TRUE(fg18.has_value());
	EXPECT_TRUE(fg18->isValid());

	const auto fg19 = metaf::FixedGroup::parse("RVRNO", metaf::ReportPart::RMK);
	ASSERT_TRUE(fg19.has_value());
	EXPECT_TRUE(fg19->isValid());

	const auto fg20 = metaf::FixedGroup::parse("PWINO", metaf::ReportPart::RMK);
	ASSERT_TRUE(fg20.has_value());
	EXPECT_TRUE(fg20->isValid());

	const auto fg21 = metaf::FixedGroup::parse("PNO", metaf::ReportPart::RMK);
	ASSERT_TRUE(fg21.has_value());
	EXPECT_TRUE(fg21->isValid());

	const auto fg22 = metaf::FixedGroup::parse("FZRANO", metaf::ReportPart::RMK);
	ASSERT_TRUE(fg22.has_value());
	EXPECT_TRUE(fg22->isValid());

	const auto fg23 = metaf::FixedGroup::parse("TSNO", metaf::ReportPart::RMK);
	ASSERT_TRUE(fg23.has_value());
	EXPECT_TRUE(fg23->isValid());

	const auto fg24 = metaf::FixedGroup::parse("SLPNO", metaf::ReportPart::RMK);
	ASSERT_TRUE(fg24.has_value());
	EXPECT_TRUE(fg24->isValid());
}