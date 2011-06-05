#include <jit.h>

#define _jit this->current

#if 1
// O1 = (O2 <  O3)
void jit::ltr_i (reg32 d, reg32 s1, reg32 s2) { jit_ltr_i (d, s1, s2); }
void jit::ltr_ui (reg32 d, reg32 s1, reg32 s2) { jit_ltr_ui (d, s1, s2); }
void jit::ltr_l (reg32 d, reg32 s1, reg32 s2) { jit_ltr_l (d, s1, s2); }
void jit::ltr_ul (reg32 d, reg32 s1, reg32 s2) { jit_ltr_ul (d, s1, s2); }
void jit::ltr_p (reg32 d, reg32 s1, reg32 s2) { jit_ltr_p (d, s1, s2); }
void jit::ltr_f (reg32 d, reg32 s1, reg32 s2) { jit_ltr_f (d, s1, s2); }
void jit::ltr_d (reg32 d, reg32 s1, reg32 s2) { jit_ltr_d (d, s1, s2); }

// O1 = (O2 <  O3)
void jit::lti_i (reg32 d, reg32 s1, reg32 s2) { jit_lti_i (d, s1, s2); }
void jit::lti_ui (reg32 d, reg32 s1, reg32 s2) { jit_lti_ui (d, s1, s2); }
void jit::lti_l (reg32 d, reg32 s1, reg32 s2) { jit_lti_l (d, s1, s2); }
void jit::lti_ul (reg32 d, reg32 s1, reg32 s2) { jit_lti_ul (d, s1, s2); }
void jit::lti_p (reg32 d, reg32 s1, reg32 s2) { jit_lti_p (d, s1, s2); }

// O1 = (O2 <= O3)
void jit::ler_i (reg32 d, reg32 s1, reg32 s2) { jit_ler_i (d, s1, s2); }
void jit::ler_ui (reg32 d, reg32 s1, reg32 s2) { jit_ler_ui (d, s1, s2); }
void jit::ler_l (reg32 d, reg32 s1, reg32 s2) { jit_ler_l (d, s1, s2); }
void jit::ler_ul (reg32 d, reg32 s1, reg32 s2) { jit_ler_ul (d, s1, s2); }
void jit::ler_p (reg32 d, reg32 s1, reg32 s2) { jit_ler_p (d, s1, s2); }
void jit::ler_f (reg32 d, reg32 s1, reg32 s2) { jit_ler_f (d, s1, s2); }
void jit::ler_d (reg32 d, reg32 s1, reg32 s2) { jit_ler_d (d, s1, s2); }

// O1 = (O2 <= O3)
void jit::lei_i (reg32 d, reg32 s1, reg32 s2) { jit_lei_i (d, s1, s2); }
void jit::lei_ui (reg32 d, reg32 s1, reg32 s2) { jit_lei_ui (d, s1, s2); }
void jit::lei_l (reg32 d, reg32 s1, reg32 s2) { jit_lei_l (d, s1, s2); }
void jit::lei_ul (reg32 d, reg32 s1, reg32 s2) { jit_lei_ul (d, s1, s2); }
void jit::lei_p (reg32 d, reg32 s1, reg32 s2) { jit_lei_p (d, s1, s2); }

// O1 = (O2 >  O3)
void jit::gtr_i (reg32 d, reg32 s1, reg32 s2) { jit_gtr_i (d, s1, s2); }
void jit::gtr_ui (reg32 d, reg32 s1, reg32 s2) { jit_gtr_ui (d, s1, s2); }
void jit::gtr_l (reg32 d, reg32 s1, reg32 s2) { jit_gtr_l (d, s1, s2); }
void jit::gtr_ul (reg32 d, reg32 s1, reg32 s2) { jit_gtr_ul (d, s1, s2); }
void jit::gtr_p (reg32 d, reg32 s1, reg32 s2) { jit_gtr_p (d, s1, s2); }
void jit::gtr_f (reg32 d, reg32 s1, reg32 s2) { jit_gtr_f (d, s1, s2); }
void jit::gtr_d (reg32 d, reg32 s1, reg32 s2) { jit_gtr_d (d, s1, s2); }

// O1 = (O2 >  O3)
void jit::gti_i (reg32 d, reg32 s1, reg32 s2) { jit_gti_i (d, s1, s2); }
void jit::gti_ui (reg32 d, reg32 s1, reg32 s2) { jit_gti_ui (d, s1, s2); }
void jit::gti_l (reg32 d, reg32 s1, reg32 s2) { jit_gti_l (d, s1, s2); }
void jit::gti_ul (reg32 d, reg32 s1, reg32 s2) { jit_gti_ul (d, s1, s2); }
void jit::gti_p (reg32 d, reg32 s1, reg32 s2) { jit_gti_p (d, s1, s2); }

// O1 = (O2 >= O3)
void jit::ger_i (reg32 d, reg32 s1, reg32 s2) { jit_ger_i (d, s1, s2); }
void jit::ger_ui (reg32 d, reg32 s1, reg32 s2) { jit_ger_ui (d, s1, s2); }
void jit::ger_l (reg32 d, reg32 s1, reg32 s2) { jit_ger_l (d, s1, s2); }
void jit::ger_ul (reg32 d, reg32 s1, reg32 s2) { jit_ger_ul (d, s1, s2); }
void jit::ger_p (reg32 d, reg32 s1, reg32 s2) { jit_ger_p (d, s1, s2); }
void jit::ger_f (reg32 d, reg32 s1, reg32 s2) { jit_ger_f (d, s1, s2); }
void jit::ger_d (reg32 d, reg32 s1, reg32 s2) { jit_ger_d (d, s1, s2); }

// O1 = (O2 >= O3)
void jit::gei_i (reg32 d, reg32 s1, reg32 s2) { jit_gei_i (d, s1, s2); }
void jit::gei_ui (reg32 d, reg32 s1, reg32 s2) { jit_gei_ui (d, s1, s2); }
void jit::gei_l (reg32 d, reg32 s1, reg32 s2) { jit_gei_l (d, s1, s2); }
void jit::gei_ul (reg32 d, reg32 s1, reg32 s2) { jit_gei_ul (d, s1, s2); }
void jit::gei_p (reg32 d, reg32 s1, reg32 s2) { jit_gei_p (d, s1, s2); }

// O1 = (O2 == O3)
void jit::eqr_i (reg32 d, reg32 s1, reg32 s2) { jit_eqr_i (d, s1, s2); }
void jit::eqr_ui (reg32 d, reg32 s1, reg32 s2) { jit_eqr_ui (d, s1, s2); }
void jit::eqr_l (reg32 d, reg32 s1, reg32 s2) { jit_eqr_l (d, s1, s2); }
void jit::eqr_ul (reg32 d, reg32 s1, reg32 s2) { jit_eqr_ul (d, s1, s2); }
void jit::eqr_p (reg32 d, reg32 s1, reg32 s2) { jit_eqr_p (d, s1, s2); }
void jit::eqr_f (reg32 d, reg32 s1, reg32 s2) { jit_eqr_f (d, s1, s2); }
void jit::eqr_d (reg32 d, reg32 s1, reg32 s2) { jit_eqr_d (d, s1, s2); }

// O1 = (O2 == O3)
void jit::eqi_i (reg32 d, reg32 s1, reg32 s2) { jit_eqi_i (d, s1, s2); }
void jit::eqi_ui (reg32 d, reg32 s1, reg32 s2) { jit_eqi_ui (d, s1, s2); }
void jit::eqi_l (reg32 d, reg32 s1, reg32 s2) { jit_eqi_l (d, s1, s2); }
void jit::eqi_ul (reg32 d, reg32 s1, reg32 s2) { jit_eqi_ul (d, s1, s2); }
void jit::eqi_p (reg32 d, reg32 s1, reg32 s2) { jit_eqi_p (d, s1, s2); }

// O1 = (O2 != O3)
void jit::ner_i (reg32 d, reg32 s1, reg32 s2) { jit_ner_i (d, s1, s2); }
void jit::ner_ui (reg32 d, reg32 s1, reg32 s2) { jit_ner_ui (d, s1, s2); }
void jit::ner_l (reg32 d, reg32 s1, reg32 s2) { jit_ner_l (d, s1, s2); }
void jit::ner_ul (reg32 d, reg32 s1, reg32 s2) { jit_ner_ul (d, s1, s2); }
void jit::ner_p (reg32 d, reg32 s1, reg32 s2) { jit_ner_p (d, s1, s2); }
void jit::ner_f (reg32 d, reg32 s1, reg32 s2) { jit_ner_f (d, s1, s2); }
void jit::ner_d (reg32 d, reg32 s1, reg32 s2) { jit_ner_d (d, s1, s2); }

// O1 = (O2 != O3)
void jit::nei_i (reg32 d, reg32 s1, reg32 s2) { jit_nei_i (d, s1, s2); }
void jit::nei_ui (reg32 d, reg32 s1, reg32 s2) { jit_nei_ui (d, s1, s2); }
void jit::nei_l (reg32 d, reg32 s1, reg32 s2) { jit_nei_l (d, s1, s2); }
void jit::nei_ul (reg32 d, reg32 s1, reg32 s2) { jit_nei_ul (d, s1, s2); }
void jit::nei_p (reg32 d, reg32 s1, reg32 s2) { jit_nei_p (d, s1, s2); }

// O1 = !(O2 >= O3)
void jit::unltr_f (reg32 d, reg32 s1, reg32 s2) { jit_unltr_f (d, s1, s2); }
void jit::unltr_d (reg32 d, reg32 s1, reg32 s2) { jit_unltr_d (d, s1, s2); }

// O1 = !(O2 >  O3)
void jit::unler_f (reg32 d, reg32 s1, reg32 s2) { jit_unler_f (d, s1, s2); }
void jit::unler_d (reg32 d, reg32 s1, reg32 s2) { jit_unler_d (d, s1, s2); }

// O1 = !(O2 <= O3)
void jit::ungtr_f (reg32 d, reg32 s1, reg32 s2) { jit_ungtr_f (d, s1, s2); }
void jit::ungtr_d (reg32 d, reg32 s1, reg32 s2) { jit_ungtr_d (d, s1, s2); }

// O1 = !(O2 <  O3)
void jit::unger_f (reg32 d, reg32 s1, reg32 s2) { jit_unger_f (d, s1, s2); }
void jit::unger_d (reg32 d, reg32 s1, reg32 s2) { jit_unger_d (d, s1, s2); }

// O1 = !(O2 <  O3) && !(O2 >  O3)
void jit::uneqr_f (reg32 d, reg32 s1, reg32 s2) { jit_uneqr_f (d, s1, s2); }
void jit::uneqr_d (reg32 d, reg32 s1, reg32 s2) { jit_uneqr_d (d, s1, s2); }

// O1 = !(O2 >= O3) || !(O2 <= O3)
void jit::ltgtr_f (reg32 d, reg32 s1, reg32 s2) { jit_ltgtr_f (d, s1, s2); }
void jit::ltgtr_d (reg32 d, reg32 s1, reg32 s2) { jit_ltgtr_d (d, s1, s2); }

// O1 =  (O2 == O2) &&  (O3 == O3)
void jit::ordr_f (reg32 d, reg32 s1, reg32 s2) { jit_ordr_f (d, s1, s2); }
void jit::ordr_d (reg32 d, reg32 s1, reg32 s2) { jit_ordr_d (d, s1, s2); }

// O1 =  (O2 != O2) ||  (O3 != O3)
void jit::unordr_f (reg32 d, reg32 s1, reg32 s2) { jit_unordr_f (d, s1, s2); }
void jit::unordr_d (reg32 d, reg32 s1, reg32 s2) { jit_unordr_d (d, s1, s2); }
#endif
