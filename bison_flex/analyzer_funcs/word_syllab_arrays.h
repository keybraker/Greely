#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define UNDER     "\033[4m"
#define DEUNDER   "\033[0m"
#define a_c_r     "\x1b[31m"
#define a_c_g     "\x1b[32m"
#define a_c_y     "\x1b[33m"
#define a_c_b     "\x1b[34m"
#define a_c_m     "\x1b[35m"
#define a_c_c     "\x1b[36m"
#define a_c_re    "\x1b[0m"
#define under     "\e[4m"
#define under_re  "\e[0m"
#define italic    "\e[3m"
#define italic_re "\e[0m"
#define bold      "\e[1m"
#define bold_re   "\e[0m"

char *mikra[31] = {
  "α","ά","β","γ","δ","ε","έ","ζ","η","ή","θ",
  "ι","ί","κ","λ","μ","ν","ξ","ο","ό","π","ρ",
  "σ","τ","υ","ύ","φ","χ","ψ","ω","ώ"
};

char *megala[31] = {
  "Α","Ά","Β","Γ","Δ","Ε","Έ","Ζ","Η","Ή","Θ",
  "Ι","Ι","Κ","Λ","Μ","Ν","Ξ","Ο","Ό","Π","Ρ",
  "Σ","Τ","Υ","Ύ","Φ","Χ","Ψ","Ω","Ώ"
};

char *typeToString[8] = { 
  "ρήμα",
  "επίθετο",
  "ουσιαστικό",
  "μετοχή",
  "αριθμητικό", 
  "επίρημα", 
  "σύνδεσμος",
  "αντονυμία" 
};

char *xronos[9] = { 
  "Ενεστώτα",
  "Παρατατικο",
  "Αόριστο",
  "Εξακολουθητικό Μέλλοντα",
  "Στιγμιαίο Μέλλοντα", 
  "Συντεταγμένο Μέλλοντα", 
  "Συντελεμένο Μέλλοντα",
  "Παρακείμενο",
  "Υπερυντέλικο"
};

char *prosopo[3] = { 
  "πρώτο",
  "δεύτερο",
  "τρίτο"
};

char *arithmos[2] = { 
  "ενικού",
  "πληθυντικού"
};

char *klisi[4] = { 
  "οριστικής",
  "υποτακτικής",
  "προστακτικής",
  "απαρέμφατος"
};

char *foni[2] = { 
  "ενεργητικής",
  "παθητικής"
};

char *genos[3] = { 
  "αρσενικό",
  "θηλύκο",
  "ουδέτερο"
};

char *ptosi[4] = { 
  "ονομαστική",
  "γενική",
  "αιτιατική",
  "κλητική"
};

char *epirimata[7] = { 
  "τοπικό",
  "χρονικό",
  "τροπικό",
  "ποσοτικό",
  "βεβαιωτικό", 
  "διστακτικό",
  "αρνητικό"
};

char *sundesmos[15] = { 
  "συμπλεκτικός",
  "διαχωριστικός",
  "αντιθετικός",
  "συμπερασματικός",
  "επεξηγηματικός", 
  "ειδικός",
  "χρονικός", 
  "αιτιολογικός",
  "υποθετικός",
  "τελικός",
  "αποτελεσματικός",
  "εναντιωματικός", 
  "διστακτικός",
  "συγκριτικός",
  "βουλητικός"
};