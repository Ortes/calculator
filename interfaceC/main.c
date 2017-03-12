#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../parsing.h"
#include "../build_exp.h"
#include "../calculation.h"
#include <gtk/gtk.h>
#include "sdl_trace.h"
 
void on_activate_entry(GtkWidget *pEntry, gpointer data);
void on_calculer_button(GtkWidget *pButton, gpointer data);
 
int main(int argc, char **argv)
{
    GtkWidget *pWindow;
    GtkWidget *pVBox;
    GtkWidget *pEntry;
    GtkWidget *pButton;
    GtkWidget *pButton2;
    GtkWidget *pLabel;
 
    gtk_init(&argc, &argv);
 
    pWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(pWindow),"Calculatrice 1.0");
    gtk_window_set_default_size(GTK_WINDOW(pWindow), 320, 200);
    g_signal_connect(G_OBJECT(pWindow), "destroy", G_CALLBACK(gtk_main_quit), NULL);
 
    pVBox = gtk_vbox_new(TRUE, 0);
    gtk_container_add(GTK_CONTAINER(pWindow), pVBox);
 
    /* Creation du GtkEntry */
    pEntry = gtk_entry_new();
    /* Insertion du GtkEntry dans la GtkVBox */
    gtk_box_pack_start(GTK_BOX(pVBox), pEntry, TRUE, FALSE, 0);
 
    pButton = gtk_button_new_with_label("Calculer");
    gtk_box_pack_start(GTK_BOX(pVBox), pButton, TRUE, FALSE, 0);

    pLabel = gtk_label_new(NULL);
    gtk_box_pack_start(GTK_BOX(pVBox), pLabel, TRUE, FALSE, 0);
    
    pButton2 = gtk_button_new_with_label("Tracer");
    gtk_box_pack_start(GTK_BOX(pVBox), pButton2, TRUE, FALSE, 0);

    pLabel = gtk_label_new(NULL);
    gtk_box_pack_start(GTK_BOX(pVBox), pLabel, TRUE, FALSE, 0);

 
    /* Connexion du signal "activate" du GtkEntry */
    g_signal_connect(G_OBJECT(pEntry), "activate", G_CALLBACK(on_activate_entry), (GtkWidget*) pLabel);
 
    /* Connexion du signal "clicked" du GtkButton */
    /* La donnee supplementaire est la GtkVBox pVBox */
    g_signal_connect(G_OBJECT(pButton), "clicked", G_CALLBACK(on_calculer_button), (GtkWidget*) pVBox);

    g_signal_connect(G_OBJECT(pButton2), "clicked",G_CALLBACK(on_calculer_button), (GtkWidget*) pVBox);
 
    gtk_widget_show_all(pWindow);
 
    gtk_main();
 
    return EXIT_SUCCESS;
}
 
/* Fonction callback execute lors du signal "activate" */
void on_activate_entry(GtkWidget *pEntry, gpointer data)
{
    const gchar *sText;
 
    /* Recuperation du texte contenu dans le GtkEntry */
    sText = gtk_entry_get_text(GTK_ENTRY(pEntry));
 
    /* Modification du texte contenu dans le GtkLabel */
    gtk_label_set_text(GTK_LABEL((GtkWidget*)data), sText);
}
 
/* Fonction callback executee lors du signal "clicked" */
void on_calculer_button(GtkWidget *pButton, gpointer data)
{
    GtkWidget *pTempEntry;
    GtkWidget *pTempLabel;
    GList *pList;
    const gchar *sText;
    char *Text = malloc(sizeof(char)*256);
    /* Recuperation de la liste des elements que contient la GtkVBox */
    pList = gtk_container_get_children(GTK_CONTAINER((GtkWidget*)data));
 
    /* Le premier element est le GtkEntry */
    pTempEntry = GTK_WIDGET(pList->data);
 
    /* Passage a l element suivant : le GtkButton */
    pList = g_list_next(pList);
 
    /* Passage a l element suivant : le GtkLabel */
    pList = g_list_next(pList);
 
    /* Cet element est le GtkLabel */
    pTempLabel = GTK_WIDGET(pList->data);
 
    /* Recuperation du texte contenu dans le GtkEntry */
    sText = gtk_entry_get_text(GTK_ENTRY(pTempEntry)); 
    /* Modification du texte contenu dans le GtkLabel */
    strncpy(Text,sText,255);
    double n  = solve(parse(Text));
    sprintf(Text,"%f",n);    
    gtk_label_set_text(GTK_LABEL(pTempLabel), Text);
 
    /* Liberation de la memoire utilisee par la liste */
    g_list_free(pList);
    free(Text);
}

void on_trace_button(GtkWidget *pbutton, gpointer data){
  GtkWidget *pTempEntry;
  GtkWidget *pTempLabel;
  GList *pList;
  char *Text = malloc(sizeof(char)*256);  

  pList = gtk_container_get_children(GTK_CONTAINER((GtkWidget*)data));
  pTempEntry = GTK_WIDGET(pList->data);
  pList = g_list_next(pList);
  const gchar *sText;
  sText = gtk_entry_get_text(GTK_ENTRY(pTempEntry));
  strncpy(Text,sText,255);
  trace(Text);
  g_list_free(pList);
}
