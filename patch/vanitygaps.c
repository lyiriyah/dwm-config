/* Settings */
static int enablegaps = 1;

static void togglegaps(const Arg *arg) {
  enablegaps = !enablegaps;
  arrange(NULL);
}

static void getgaps(Monitor *m, int *oh, int *ov, int *ih, int *iv,
                    unsigned int *nc) {
  unsigned int n, oe, ie;
  oe = ie = enablegaps;
  Client *c;

  for (n = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next), n++)
    ;
  if (n == 1) {
    oe *= smartgaps_fact; // outer gaps disabled or multiplied when only one
                          // client
  }

  *oh = m->gappoh * oe; // outer horizontal gap
  *ov = m->gappov * oe; // outer vertical gap
  *ih = m->gappih * ie; // inner horizontal gap
  *iv = m->gappiv * ie; // inner vertical gap
  *nc = n;              // number of clients
}
