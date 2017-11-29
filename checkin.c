#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

typedef struct PARTICIPANT
{
    string name;
    bool checked_in;
    struct PARTICIPANT* next;

}
PARTICIPANT;

PARTICIPANT* first_participant = NULL;
//PARTICIPANT* current_participant = NULL;

#define CHECKED_IN true
#define CHECKED_OUT false

string get_user_input();
bool perform(string user_input);

// TODO: Functions to implement
void add_one(string participant_name);
void remove_one(string participant_name);
void check_one(string participant_name);
void display_participants();
void free_memory();

int main(void)
{
    bool working = true;

    while(working)
    {
        string user_input = get_user_input();
        working = perform(user_input);
    }

    free_memory();
}

string get_user_input()
{
    return get_string("Command: ");
}

// Performs the action from the "user_input"
bool perform(string user_input)
{
    // Read the string of user input into two variables
    string action_name = strtok(user_input, " ");
    string participant_name = strtok(NULL, " ");

    if(strcmp(action_name, "add") == 0)
    {
        add_one(participant_name);
        return true;
    }
    if(strcmp(action_name, "remove") == 0)
    {
        remove_one(participant_name);
        return true;
    }
    if(strcmp(action_name, "check") == 0)
    {
        check_one(participant_name);
        return true;
    }
    if(strcmp(action_name, "display") == 0)
    {
       display_participants();
       return true;
    }
    if(strcmp(action_name, "exit") == 0)
    {
        return false;
    }

    return true;
}

/*
    Adds a participant to the beginning of the list
*/
void add_one(string participant_name)
{
    printf("add %s\n", participant_name);
    PARTICIPANT *participant_new = malloc(sizeof(PARTICIPANT));
   // participant_new =PARTICIPANTS;
    if (first_participant == NULL)
    {
        first_participant = participant_new ;
        participant_new->next = NULL;
    }
    else
    {
       participant_new->next = first_participant;
       first_participant    = participant_new ;
    }

    participant_new->name = participant_name;
    participant_new->checked_in =CHECKED_OUT;

    //current_participant = participant_new;
    //current_participant->next = NULL;

}

/*
    Search for a participant in the list and if it exists, remove it.
*/
void remove_one(string participant_name)
{
    printf("remove %s\n", participant_name);
    PARTICIPANT* participant_current=NULL;
    PARTICIPANT* participant_previous=NULL;

    if (first_participant == NULL)
    {
        free(first_participant);
    }
    else
    {
       participant_new->next = first_participant;
       first_participant    = participant_new ;
    }

    while (first_participant != NULL)
    {
        if(strcmp(participant_current->name, participant_name)==0)
        {
            participant_previous->next = participant_current->next;
            free(participant_current);
            //free(participant_new);
        }

        first_participant = first_participant->next;
    }
}

/*
    Check a participant from the list in or out
*/
void check_one(string participant_name)
{
    printf("check %s\n", participant_name);

        first_participant->checked_in = CHECKED_IN;
       // participants->next = NULL;

       // current_participant = new_participant;
}

/*
    Display all participants and their status.
*/
void display_participants()
{

    printf("display\n");
    PARTICIPANT * current_participant = first_participant;

    /*
    if (first_participant == NULL)
    {
            printf("Name: %s \n", first_participant->name);
            printf("Status: %i \n", first_participant->checked_in);
            return;
    }*/


    while(current_participant != NULL)
    {
            printf("Name: %s \n", current_participant->name);
            printf("Status: %i \n", current_participant->checked_in);
            current_participant = current_participant->next;
    }

}
/*
    Free all memory used by participants in the list
*/
void free_memory()
{
    printf("freeing stuff.\n");

    // TODO
}
