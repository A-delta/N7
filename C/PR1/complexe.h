#ifndef COMPLEX_H
#define COMPLEX_H

// Type utilisateur complexe_t
typedef struct complexe_t
{
    double partie_reelle;
    double partie_imaginaire;
} complexe_t;

// Fonctions reelle et imaginaire
/**
 * reelle
 *
 * Retourne la partie réelle d'un nombre complexe
 *
 * Paramètres :
 *      c [in] le nombre complexe à modifier
 *
 * Retourne la partie réelle de c
 *
 * Pré-conditions : c non-null
 * */
double reelle(complexe_t c);

/**
 * imaginaire
 *
 * Retourne la partie imaginaire d'un nombre complexe
 *
 * Paramètres :
 *      c : le nombre complexe à modifier
 *
 * Retour : la partie imaginaire de c
 *
 * Pré-conditions : c non-null
 */
double imaginaire(complexe_t c);

// Procédures set_reelle, set_imaginaire et init
/**
 * set_reelle
 *
 * Modifie la partie réelle du nombre complexe c
 *
 * Paramètres :
 *      c   [ou]     le nombre complexe à modifier
 *      v   [in]    la nouvelle partie réelle
 *
 * Pré-conditions : c non-null
 * Post-conditions : c.reelle = v
 */
void set_reelle(complexe_t *c, double v);

/**
 * set_imaginaire
 *
 * Modifie la partie imaginaire du nombre complexe c
 *
 * Paramètres :
 *      c   [ou]     le nombre complexe à modifier
 *      v   [in]    la nouvelle partie imaginaire
 *
 * Pré-conditions : c non-null
 * Post-conditions : c.imaginaire = v
 */
void set_imaginaire(complexe_t *c, double v);

/**
 * init
 *
 * Initialise le nombre complexe c avec la partie réelle et la partie imaginaire données
 *
 * Paramètres :
 *      c   [out]     le nombre complexe à modifier
 *      a   [in]     la nouvelle partie réelle
 *      b   [in]     la nouvelle partie imaginaire
 *
 * Pré-conditions : c non-null
 * Post-conditions : c.reelle = a && c.imaginaire = b
 */
void init(complexe_t *c, double a, double b);

// Procédure copie
/**
 * copie
 * Copie les composantes du complexe donné en second argument dans celles du premier
 * argument
 *
 * Paramètres :
 *   resultat       [out]   Complexe dans lequel copier les composantes
 *   autre          [in]    Complexe à copier
 *
 * Pré-conditions : resultat non null
 * Post-conditions : resultat et autre ont les mêmes composantes
 */
void copie(complexe_t *resultat, complexe_t autre);

// Algèbre des nombres complexes
/**
 * conjugue
 * Calcule le conjugué du nombre complexe op et le sotocke dans resultat.
 *
 * Paramètres :
 *   resultat       [out] Résultat de l'opération
 *   op             [in]  Complexe dont on veut le conjugué
 *
 * Pré-conditions : resultat non-null
 * Post-conditions : reelle(*resultat) = reelle(op), complexe(*resultat) = - complexe(op)
 */
void conjugue(complexe_t *resultat, complexe_t op);

/**
 * ajouter
 * Réalise l'addition des deux nombres complexes gauche et droite et stocke le résultat
 * dans resultat.
 *
 * Paramètres :
 *   resultat       [out] Résultat de l'opération
 *   gauche         [in]  Opérande gauche
 *   droite         [in]  Opérande droite
 *
 * Pré-conditions : resultat non-null
 * Post-conditions : *resultat = gauche + droite
 */
void ajouter(complexe_t *resultat, complexe_t gauche, complexe_t droite);

/**
 * soustraire
 * Réalise la soustraction des deux nombres complexes gauche et droite et stocke le résultat
 * dans resultat.
 *
 * Paramètres :
 *   resultat       [out] Résultat de l'opération
 *   gauche         [in]  Opérande gauche
 *   droite         [in]  Opérande droite
 *
 * Pré-conditions : resultat non-null
 * Post-conditions : *resultat = gauche - droite
 */
void soustraire(complexe_t *resultat, complexe_t gauche, complexe_t droite);

/**
 * multiplier
 * Réalise le produit des deux nombres complexes gauche et droite et stocke le résultat
 * dans resultat.
 *
 * Paramètres :
 *   resultat       [out] Résultat de l'opération
 *   gauche         [in]  Opérande gauche
 *   droite         [in]  Opérande droite
 *
 * Pré-conditions : resultat non-null
 * Post-conditions : *resultat = gauche * droite
 */
void multiplier(complexe_t *resultat, complexe_t gauche, complexe_t droite);

/**
 * echelle
 * Calcule la mise à l'échelle d'un nombre complexe avec le nombre réel donné (multiplication
 * de op par le facteur réel facteur).
 *
 * Paramètres :
 *   resultat       [out] Résultat de l'opération
 *   op             [in]  Complexe à mettre à l'échelle
 *   facteur        [in]  Nombre réel à multiplier
 *
 * Pré-conditions : resultat non-null
 * Post-conditions : *resultat = op * facteur
 */
void echelle(complexe_t *resultat, complexe_t op, double facteur);

/**
 * puissance
 * Calcule la puissance entière du complexe donné et stocke le résultat dans resultat.
 *
 * Paramètres :
 *   resultat       [out] Résultat de l'opération
 *   op             [in]  Complexe dont on veut la puissance
 *   exposant       [in]  Exposant de la puissance
 *
 * Pré-conditions : resultat non-null, exposant >= 0
 * Post-conditions : *resultat = op * op * ... * op
 *                                 { n fois }
 */
void puissance(complexe_t *resultat, complexe_t op, int exposant);

// Module et argument
/**
 * module_carre
 * Calcule le module au carré du nombre complexe c
 *
 * Paramètres
 *      c [in] Le nombre complexe
 *
 * Retourne le module au carré de c
 *
 * Pré-conditions : c non-null
 * Post-conditions : resultat = c.partie_reelle*c.partie_reelle + c.partie_imaginaire*c.partie_imaginaire
 */
double module_carre(complexe_t c);
/**
 * module
 * Calcule le module du nombre complexe c
 *
 * Paramètres
 *      c [in] Le nombre complexe
 *
 * Retourne le module de c
 *
 * Pré-conditions : c non-null
 * Post-conditions : resultat = sqrt(c.partie_reelle*c.partie_reelle + c.partie_imaginaire*c.partie_imaginaire)
 */
double module(complexe_t c);

/**
 * argument
 * Calcule l'argument du nombre complexe c
 *
 * Paramètres
 *      c [in] Le nombre complexe
 *
 * Retourne l'argument de c
 *
 * Pré-conditions : c non-null
 * Post-conditions : resultat = arctan(c.partie_imaginaire / c.partie_reelle)
 */
double argument(complexe_t c);

#endif // COMPLEXE_H
