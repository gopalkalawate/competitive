#include <stdio.h>
#include <stdlib.h>

// Structure for a term in the polynomial
struct Term {
    int power;
    float coeff;
    struct Term* next;
};

// Function to create a new term
struct Term* createTerm(int power, float coeff) {
    struct Term* term = (struct Term*)malloc(sizeof(struct Term));
    term->power = power;
    term->coeff = coeff;
    term->next = NULL;
    return term;
}

// Function to insert a term at the end of a linked list
void insertEnd(struct Term** head, int power, float coeff) {
    struct Term* newTerm = createTerm(power, coeff);
    if (*head == NULL) {
        *head = newTerm;
        return;
    }
    struct Term* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newTerm;
}

// Function to display a polynomial
void display(struct Term* head) {
    struct Term* current = head;
    while (current != NULL) {
        printf("%.2fx^%d", current->coeff, current->power);
        current = current->next;
        if (current != NULL) {
            if (current->coeff >= 0) {
                printf(" + ");
            } else {
                printf(" - ");
            }
        }
    }
    printf("\n");
}

// Function to multiply two polynomials
struct Term* multiplyPolynomials(struct Term* p1, struct Term* p2) {
    struct Term* result = NULL;
    struct Term* current1 = p1;
    while (current1 != NULL) {
        struct Term* current2 = p2;
        while (current2 != NULL) {
            int newPower = current1->power + current2->power;
            float newCoeff = current1->coeff * current2->coeff;
            struct Term* existingTerm = result;
            while (existingTerm != NULL && existingTerm->power != newPower) {
                existingTerm = existingTerm->next;
            }
            if (existingTerm != NULL) {
                existingTerm->coeff += newCoeff;
            } else {
                insertEnd(&result, newPower, newCoeff);
            }
            current2 = current2->next;
        }
        current1 = current1->next;
    }
    return result;
}

int main() {
    struct Term* poly1 = NULL;
    struct Term* poly2 = NULL;
    int numTerms1, numTerms2;

    // Input the first polynomial
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &numTerms1);
    for (int i = 0; i < numTerms1; i++) {
        int power;
        float coeff;
        printf("Enter coefficient and power for term %d: ", i + 1);
        scanf("%f%d", &coeff, &power);
        insertEnd(&poly1, power, coeff);
    }

    // Input the second polynomial
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &numTerms2);
    for (int i = 0; i < numTerms2; i++) {
        int power;
        float coeff;
        printf("Enter coefficient and power for term %d: ", i + 1);
        scanf("%f%d", &coeff, &power);
        insertEnd(&poly2, power, coeff);
    }

    // Multiply the polynomials and display the result
    struct Term* result = multiplyPolynomials(poly1, poly2);
    printf("Resultant Polynomial: ");
    display(result);

    // Clean up
    struct Term* temp;
    while (poly1 != NULL) {
        temp = poly1;
        poly1 = poly1->next;
        free(temp);
    }
    while (poly2 != NULL) {
        temp = poly2;
        poly2 = poly2->next;
        free(temp);
    }
    while (result != NULL) {
        temp = result;
        result = result->next;
        free(temp);
    }

    return 0;
}
